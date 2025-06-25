#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	int	fd[2];
	pid_t	pid;
	char	buf[100];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(fd[1]);
		read(fd[0], buf, sizeof(buf));
		printf("Child process received: %s\n", buf);

		close (fd[0]);
	}
	else
	{
		const char	*message = "Hello from parent process!";
		close(fd[0]);
		write(fd[1], message, strlen(message) + 1);
		close(fd[1]);
	}
	return (0);
}