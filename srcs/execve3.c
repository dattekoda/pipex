#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

extern char	**environ;

int	main(void)
{
	pid_t	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		char *const	argv[] = {"cat", "infile", NULL};
		execve("/bin/cat", argv, environ);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	printf("Parent: (pid = %d)\n", pid);
	int	status;
	waitpid(pid, &status, 0);
	printf("Parent: child's exit status: %d\n", WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}