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
		
}