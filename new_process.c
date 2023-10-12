#include "shell.h"


int new_process(char **args)
{
	/* Set up signal handling for SIGINT in parent process (shell) to ignore */
	signal(SIGINT, SIG_IGN);
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{	/* Reset default signal handling for SIGINT in child process */
		signal(SIGINT, SIG_DFL);
	
		/* child process */
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("error in new_process: forking");
	}
	else
	{
		/* parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
