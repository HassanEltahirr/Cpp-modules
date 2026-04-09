# Minishell (Phase 1)

A small CLI shell in C that supports:
- Built-in commands
- External command execution (`fork` + `execvp`)
- Pipelines (`|`) with 1, 2, 3, or more stages

## Project Structure

This version is split for readability, while staying compact:

- `minishell.h`  
  Shared limits and function prototypes.
- `main.c`  
  Program entry point.
- `shell.c`  
  REPL loop and per-line processing.
- `parser.c`  
  Command line parsing and pipeline/token splitting.
- `executor.c`  
  Single-command and pipeline execution (`fork`, `execvp`, `pipe`, `dup2`, `waitpid`).
- `builtins.c`  
  Built-in commands and dispatcher.
- `utils.c`  
  Small shared helpers.

## Build

```bash
make
```

Run:

```bash
./minishell
```

Clean objects:

```bash
make clean
```

Remove objects + binary:

```bash
make fclean
```

Rebuild from scratch:

```bash
make re
```

## Built-in Commands

Implemented built-ins:

1. `cd [dir]`
2. `pwd`
3. `echo [args]`
4. `exit [status]`
5. `env`
6. `help`
7. `mkdir dir`
8. `rmdir dir`
9. `touch file`
10. `clear`
11. `hostname`
12. `whoami`
13. `date`
14. `sleep sec`
15. `which cmd`

External commands also work (examples: `ls`, `ls -l`, `rm`, `cat`, `grep`, `wc`, ...).

## Pipe Examples

One pipe:

```bash
ls | wc -l
```

Two pipes:

```bash
ls | grep minishell | wc -l
```

Three pipes:

```bash
ls | grep .c | sort | wc -l
```

## Notes / Limits

- Basic quoting is supported for `'...'` and `"..."` during token parsing.
- This phase does **not** implement redirections (`>`, `<`, `>>`) or job control.
- `exit` as a single command exits the shell.
