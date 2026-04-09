#include "minishell.h"

#include <ctype.h>
#include <stddef.h>

int split_pipeline(char *line, char *segs[], int max_segs)
{
	int n = 0;
	int in_single = 0;
	int in_double = 0;
	char *w = line;

	for (char *p = line; *p; p++) {
		if (*p == '\'' && !in_double)
			in_single = !in_single;
		else if (*p == '"' && !in_single)
			in_double = !in_double;
		else if (*p == '|' && !in_single && !in_double) {
			if (n >= max_segs)
				return -1;
			*p = '\0';
			trim_inplace(w);
			if (*w == '\0')
				return -1;
			segs[n++] = w;
			w = p + 1;
		}
	}
	trim_inplace(w);
	if (*w == '\0')
		return -1;
	if (n >= max_segs)
		return -1;
	segs[n++] = w;
	return n;
}

int tokenize_segment(char *seg, char *argv[], int max_args)
{
	int argc = 0;
	char *p = seg;

	while (*p) {
		while (*p && isspace((unsigned char)*p))
			p++;
		if (!*p)
			break;
		if (argc >= max_args - 1)
			return -1;

		char quote = 0;
		if (*p == '\'' || *p == '"')
			quote = *p++;

		char *start = p;
		if (quote) {
			while (*p && *p != quote)
				p++;
			if (!*p)
				return -1;
			*p++ = '\0';
		} else {
			while (*p && !isspace((unsigned char)*p))
				p++;
			if (*p)
				*p++ = '\0';
		}
		argv[argc++] = start;
	}
	argv[argc] = NULL;
	return argc;
}
