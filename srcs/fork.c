#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;

	printf("Before fork (pid: %d)\n", getpid());
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
		printf("Hello from child process! (pid: %d, parent pid: %d)\n", getpid(), getppid());
	else
	{
		printf("Hello from parent process! (child pid: %d, child pid: %d)\n", getpid(), pid);
		wait(NULL);
	}
	printf("Both parent and child reach here (pid: %d)\n", getpid());
	return (0);
}
