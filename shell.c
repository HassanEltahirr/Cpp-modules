#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int process_line(char *line)
{
	char *segs[MAX_SEGS];
	char *argv_bufs[MAX_SEGS][MAX_ARGS];
	char **cmdv[MAX_SEGS];

	trim_inplace(line);
	if (*line == '\0')
		return 0;

	int nseg = split_pipeline(line, segs, MAX_SEGS);
	if (nseg < 0) {
		fprintf(stderr, "minishell: invalid pipeline\n");
		return 1;
	}

	for (int i = 0; i < nseg; i++) {
		int argc = tokenize_segment(segs[i], argv_bufs[i], MAX_ARGS);
		if (argc < 0) {
			fprintf(stderr, "minishell: too many tokens or bad quotes\n");
			return 1;
		}
		cmdv[i] = argv_bufs[i];
	}

	if (nseg == 1 && strcmp(cmdv[0][0], "exit") == 0) {
		int code = 0;

		if (cmdv[0][1])
			code = atoi(cmdv[0][1]);
		exit(code);
	}

	if (nseg > 1)
		return run_pipeline(cmdv, nseg);
	return run_simple(cmdv[0]);
}

void shell_loop(void)
{
	char line[MAX_LINE];

	while (1) {
		char cwd[MAX_LINE];
		const char *prompt_cwd = "";

		if (getcwd(cwd, sizeof(cwd)))
			prompt_cwd = cwd;
		printf("minishell:%s$ ", prompt_cwd);
		fflush(stdout);

		if (!fgets(line, sizeof(line), stdin)) {
			putchar('\n');
			break;
		}

		size_t len = strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = '\0';

		process_line(line);
		fflush(stdout);
		fflush(stderr);
	}
}
