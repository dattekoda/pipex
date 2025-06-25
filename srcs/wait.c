#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid = fork();

	if (pid == 0)
	{
		printf("Child process runnning\n");
		_exit(0);
	}
	else
	{
		int	status;
		wait(&status);
		printf("Child process finished with status %d\n", WEXITSTATUS(status));
	}
	return (0);
}