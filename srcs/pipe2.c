#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

# define READ 0
# define WRITE 1

int	popen2(int *fd_r, int *fd_w)
{
	int	pipe_c2p[2];
	int	pipe_p2c[2];
	int	pid;

	if (pipe(pipe_c2p) < 0)
		return (perror("popen2"), 1);
	if (pipe(pipe_c2p) < 0)
		return (perror("popen2")
		, close(pipe_c2p[READ])
		, close(pipe_c2p[WRITE]), 1);
	if ((pid = fork()) < 0)
		return (perror("fork")
		, close(pipe_c2p[READ])
		, close(pipe_c2p[WRITE])
		, close(pipe_p2c[READ])
		, close(pipe_p2c[WRITE]), 1);
	if (pid == 0)
	{
		// 子プロセスの場合は、親から子へ書き込み、子から親への読み込みはない。
		close(pipe_p2c[WRITE]);
		close(pipe_c2p[READ]);
		dup2(pipe_p2c[READ], 0);
		dup2(pipe_c2p[WRITE], 1);
		close(pipe_p2c[READ]);
		close(pipe_c2p[WRITE]);
		if (execl("./test1", "./test1", NULL) < 0)
		{
			perror("execl");
			return (1);
		}
	}
	close(pipe_p2c[READ]);
	close(pipe_c2p[WRITE]);
	*fd_r = pipe_c2p[READ];
	*fd_w = pipe_p2c[WRITE];
	return (pid);
}

int	main(int argc, char *argv[])
{
	int	fd_r = STDIN_FILENO;
	int	fd_w = STDOUT_FILENO;
	char	buf[255];

	if (argc < 2)
		return (perror("argv"), 1);
	popen2(&fd_r, &fd_w);
	write(fd_w, argv[1], strlen(argv[1]));
	int	size = read(fd_r, buf, sizeof(buf));
	if (size == -1)
		return (perror("read"), 1);
	printf("test2: ");
	fflush(stdout);
	write(1, buf, size);
	printf("\n");
	return (0);
}