#include "minishell.h"

#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

extern char **environ;

static void builtin_help(void)
{
	puts("Built-in commands:");
	puts("  cd [dir]     - change directory (default: HOME)");
	puts("  pwd          - print working directory");
	puts("  echo [args]  - print arguments");
	puts("  exit [n]     - exit with status (default 0)");
	puts("  env          - print environment");
	puts("  mkdir DIR    - create directory (mode 0755)");
	puts("  rmdir DIR    - remove empty directory");
	puts("  touch FILE   - create or update file timestamp");
	puts("  clear        - clear screen (ANSI)");
	puts("  hostname     - print host name");
	puts("  whoami       - print effective user name");
	puts("  date         - print local date/time");
	puts("  sleep SEC    - sleep for integer seconds");
	puts("  which CMD    - show path to CMD on PATH");
	puts("  help         - this message");
	puts("External commands: ls, ls -l, rm, cat, grep, wc, ...");
}

static int builtin_cd(char **argv)
{
	const char *target = argv[1];

	if (!target) {
		target = getenv("HOME");
		if (!target) {
			fprintf(stderr, "cd: HOME not set\n");
			return 1;
		}
	}
	if (chdir(target) != 0) {
		perror("cd");
		return 1;
	}
	return 0;
}

static int builtin_pwd(void)
{
	char buf[MAX_LINE];

	if (!getcwd(buf, sizeof(buf))) {
		perror("pwd");
		return 1;
	}
	puts(buf);
	return 0;
}

static int builtin_echo(char **argv)
{
	for (int i = 1; argv[i]; i++) {
		if (i > 1)
			putchar(' ');
		fputs(argv[i], stdout);
	}
	putchar('\n');
	return 0;
}

static int builtin_env(void)
{
	for (char **e = environ; *e; e++)
		puts(*e);
	return 0;
}

static int builtin_mkdir(char **argv)
{
	if (!argv[1]) {
		fprintf(stderr, "mkdir: missing operand\n");
		return 1;
	}
	if (mkdir(argv[1], 0755) != 0) {
		perror("mkdir");
		return 1;
	}
	return 0;
}

static int builtin_rmdir(char **argv)
{
	if (!argv[1]) {
		fprintf(stderr, "rmdir: missing operand\n");
		return 1;
	}
	if (rmdir(argv[1]) != 0) {
		perror("rmdir");
		return 1;
	}
	return 0;
}

static int builtin_touch(char **argv)
{
	if (!argv[1]) {
		fprintf(stderr, "touch: missing operand\n");
		return 1;
	}
	int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
	if (fd < 0) {
		perror("touch");
		return 1;
	}
	close(fd);
	return 0;
}

static int builtin_clear(void)
{
	fputs("\033[2J\033[H", stdout);
	fflush(stdout);
	return 0;
}

static int builtin_hostname(void)
{
	char buf[256];

	if (gethostname(buf, sizeof(buf)) != 0) {
		perror("hostname");
		return 1;
	}
	puts(buf);
	return 0;
}

static int builtin_whoami(void)
{
	struct passwd *pw = getpwuid(getuid());

	if (!pw) {
		perror("whoami");
		return 1;
	}
	puts(pw->pw_name);
	return 0;
}

static int builtin_date(void)
{
	time_t t = time(NULL);
	char *s = ctime(&t);

	if (!s) {
		fprintf(stderr, "date: time error\n");
		return 1;
	}
	printf("%s", s);
	return 0;
}

static int builtin_sleep(char **argv)
{
	if (!argv[1]) {
		fprintf(stderr, "sleep: missing operand\n");
		return 1;
	}
	sleep((unsigned)strtoul(argv[1], NULL, 10));
	return 0;
}

static int builtin_which(char **argv)
{
	if (!argv[1]) {
		fprintf(stderr, "which: missing operand\n");
		return 1;
	}
	const char *cmd = argv[1];
	if (strchr(cmd, '/')) {
		if (access(cmd, X_OK) == 0) {
			puts(cmd);
			return 0;
		}
		fprintf(stderr, "which: %s not found\n", cmd);
		return 1;
	}

	const char *path = getenv("PATH");
	if (!path) {
		fprintf(stderr, "which: PATH not set\n");
		return 1;
	}
	char *pathdup = strdup(path);
	if (!pathdup) {
		perror("which");
		return 1;
	}
	int found = 1;
	for (char *dir = strtok(pathdup, ":"); dir; dir = strtok(NULL, ":")) {
		char cand[MAX_LINE];
		int n = snprintf(cand, sizeof(cand), "%s/%s", dir, cmd);
		if (n > 0 && (size_t)n < sizeof(cand) && access(cand, X_OK) == 0) {
			puts(cand);
			found = 0;
			break;
		}
	}
	free(pathdup);
	if (found) {
		fprintf(stderr, "which: %s not in PATH\n", cmd);
		return 1;
	}
	return 0;
}

int is_builtin(const char *name)
{
	static const char *builtins[] = {
		"cd", "pwd", "echo", "exit", "env", "help",
		"mkdir", "rmdir", "touch", "clear", "hostname",
		"whoami", "date", "sleep", "which", NULL
	};

	for (int i = 0; builtins[i]; i++) {
		if (strcmp(name, builtins[i]) == 0)
			return 1;
	}
	return 0;
}

int run_builtin(char **argv)
{
	const char *cmd = argv[0];

	if (strcmp(cmd, "cd") == 0)
		return builtin_cd(argv);
	if (strcmp(cmd, "pwd") == 0)
		return builtin_pwd();
	if (strcmp(cmd, "echo") == 0)
		return builtin_echo(argv);
	if (strcmp(cmd, "env") == 0)
		return builtin_env();
	if (strcmp(cmd, "help") == 0) {
		builtin_help();
		return 0;
	}
	if (strcmp(cmd, "mkdir") == 0)
		return builtin_mkdir(argv);
	if (strcmp(cmd, "rmdir") == 0)
		return builtin_rmdir(argv);
	if (strcmp(cmd, "touch") == 0)
		return builtin_touch(argv);
	if (strcmp(cmd, "clear") == 0)
		return builtin_clear();
	if (strcmp(cmd, "hostname") == 0)
		return builtin_hostname();
	if (strcmp(cmd, "whoami") == 0)
		return builtin_whoami();
	if (strcmp(cmd, "date") == 0)
		return builtin_date();
	if (strcmp(cmd, "sleep") == 0)
		return builtin_sleep(argv);
	if (strcmp(cmd, "which") == 0)
		return builtin_which(argv);
	return -1;
}
