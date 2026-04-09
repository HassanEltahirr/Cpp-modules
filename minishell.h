#ifndef MINISHELL_H
#define MINISHELL_H

/* Input / argv / pipeline limits */
#define MAX_LINE 4096
#define MAX_ARGS 256
#define MAX_SEGS 32

void trim_inplace(char *s);
void close_safe(int fd);

int split_pipeline(char *line, char *segs[], int max_segs);
int tokenize_segment(char *seg, char *argv[], int max_args);

int is_builtin(const char *name);
int run_builtin(char **argv);

int run_simple(char **argv);
int run_pipeline(char ***cmds, int ncmds);

int process_line(char *line);
void shell_loop(void);

#endif
