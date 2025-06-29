#include "small.h"

int	command(t_cmd *cmd, char *argv[], char *envp[])
{
	int		pipefd[2];
	int		in_fd;
	int		out_fd;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) < 0)
		perror("pipe")
	pid1 = fork();
	if (pid1 == 0)
	{
		in_fd = open(argv[1], O_RDONLY);
		if (in_fd < 0)
			return (perror("no such file")
				, close(pipefd[0]), close(pipefd[1])
				, free(cmd), exit(FAILURE), 1);
		dup2(in_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		if (execve(cmd->path1, cmd->args1, envp) < 0)
			return (close(pipefd[1]), 1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(out_fd, STDOUT_FILENO);
		close(pipefd[1]);
		if (execve(cmd->path2, cmd->args2, envp) < 0)
			return (close(pipefd[0]), 1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}