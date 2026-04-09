#include "minishell.h"

#include <ctype.h>
#include <string.h>
#include <unistd.h>

void trim_inplace(char *s)
{
	char *start = s;
	char *end;

	while (*start && isspace((unsigned char)*start))
		start++;
	if (start != s)
		memmove(s, start, strlen(start) + 1);
	end = s + strlen(s);
	while (end > s && isspace((unsigned char)end[-1]))
		end--;
	*end = '\0';
}

void close_safe(int fd)
{
	if (fd >= 0)
		close(fd);
}
