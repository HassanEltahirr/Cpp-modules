#include "minishell.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int run_simple(char **argv)
{
	if (!argv[0])
		return 0;

	int st = run_builtin(argv);
	if (st >= 0)
		return st;

	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return 1;
	}
	if (pid == 0) {
		execvp(argv[0], argv);
		fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
		_exit(127);
	}

	int status;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return WEXITSTATUS(status);
	return 1;
}

int run_pipeline(char ***cmds, int ncmds)
{
	if (ncmds == 1)
		return run_simple(cmds[0]);

	int prev_read = -1;
	pid_t pids[MAX_SEGS];
	int nkids = 0;

	for (int i = 0; i < ncmds; i++) {
		int pipefd[2] = {-1, -1};

		if (i < ncmds - 1) {
			if (pipe(pipefd) < 0) {
				perror("pipe");
				close_safe(prev_read);
				return 1;
			}
		}

		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			close_safe(prev_read);
			close_safe(pipefd[0]);
			close_safe(pipefd[1]);
			return 1;
		}

		if (pid == 0) {
			if (prev_read >= 0 && dup2(prev_read, STDIN_FILENO) < 0) {
				perror("dup2");
				_exit(1);
			}
			if (i < ncmds - 1) {
				close_safe(pipefd[0]);
				if (dup2(pipefd[1], STDOUT_FILENO) < 0) {
					perror("dup2");
					_exit(1);
				}
				close_safe(pipefd[1]);
			}
			close_safe(prev_read);
			close_safe(pipefd[0]);
			close_safe(pipefd[1]);

			if (cmds[i][0] && strcmp(cmds[i][0], "exit") == 0) {
				int code = cmds[i][1] ? atoi(cmds[i][1]) : 0;
				_exit(code);
			}
			if (cmds[i][0] && is_builtin(cmds[i][0])) {
				int child_st = run_builtin(cmds[i]);
				fflush(NULL);
				_exit(child_st < 0 ? 1 : child_st);
			}
			execvp(cmds[i][0], cmds[i]);
			fprintf(stderr, "%s: %s\n", cmds[i][0], strerror(errno));
			_exit(127);
		}

		pids[nkids++] = pid;
		close_safe(prev_read);
		close_safe(pipefd[1]);
		prev_read = pipefd[0];
	}
	close_safe(prev_read);

	int last_status = 0;
	for (int k = 0; k < nkids; k++) {
		int status;

		waitpid(pids[k], &status, 0);
		if (k == nkids - 1 && WIFEXITED(status))
			last_status = WEXITSTATUS(status);
	}
	return last_status;
}
