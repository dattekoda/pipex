#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid = fork();
	
	if (pid == 0)
	{
		printf("Hi from child\n");
		sleep(2);
		printf("Bye from child\n");
		exit(WEXITSTATUS(pid));
	}
	else if (pid > 0)
	{
		int	status;

		printf("Hi from parent\n");
		pid_t	child_pid = waitpid(pid, &status, 0);
		if (child_pid == pid)
		{
			printf("Parent: child%d has finished.\n", child_pid);
			if (WIFEXITED(status))
				printf("Parent: Child's exit code: %d\n", WEXITSTATUS(status));
		}
		else
			perror("waitpid failed");
	}
	else
		return (perror("fork failed"), 1);
	return (0);
}