#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void error_and_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	pipe_fd[2];
	pid_t	pid1, pid2;

	if (pipe(pipe_fd) == -1)
		error_and_exit("pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_and_exit("fork");
	if (pid1 == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);

		char	*cmd1_args[] = { "ls", "-l", NULL };
		execve("/bin/ls", cmd1_args, envp);
		error_and_exit("execve cmd1");
	}
	pid2 = fork();
	if (pid2 == -1)
		error_and_exit("fork");
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);

		char	*cmd2_args[] = { "wc", "-l", NULL };
		execve("/usr/bin/wc", cmd2_args, envp);
		error_and_exit("execve cmd2");
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}