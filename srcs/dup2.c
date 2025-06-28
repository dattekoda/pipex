#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int			fd;
	char		*argv[3];
	extern char	**environ;

	if ((fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0)
		return (perror("open"), -1);
	if (dup2(fd, 1) < 0)
		return (perror("dup2"), close(fd), -1);
	argv[0] = "echo";
	argv[1] = "Hello Wordld!";
	argv[2] = NULL;
	execve("/bin/echo", argv, environ);
	perror("execve");
	return (-1);
}