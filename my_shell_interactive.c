#include "shell.h"
int waiting_for_input = 0;  /* Global flag to indicate shell's state */

/* Custom signal handler for SIGINT */
void handle_sigint(int sig) {
	if (waiting_for_input) {
		write(STDOUT_FILENO, "\n", 1);  /* Print a newline for clarity */
		exit(EXIT_SUCCESS);  /* Exit the shell if waiting for user input */
	}
}

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */
void my_shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("simple_prompt$ "); /* print prompt symbol */
		waiting_for_input = 1;  /* Set flag to indicate waiting for user input */
		signal(SIGINT, handle_sigint);  /* Set the custom signal handler */
		line = read_line(); /* read line from stdin */
		waiting_for_input = 0;  /* Reset flag after reading user input */
		args = split_line(line); /* tokenize line */
		status = execute_args(args);
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit with status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
