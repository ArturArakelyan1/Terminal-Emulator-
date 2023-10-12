#include "shell.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */
int main()
{
	/* determines if file descriptor is associated with a terminal */
	if (isatty(STDIN_FILENO) == 1)
	{
		my_shell_interactive();
	}
	else
	{
		my_shell_no_interactive();
	}
	return (0);
}
