#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open"), 1);

	fflush(stdout);
	int	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdout < 0)
		return (perror("dup"), close(fd), 1);
	if (dup2(fd, STDOUT_FILENO) < 0)
		return(perror("dup2"), close(fd), close(saved_stdout), 1);
	printf("Hello file!\n");
	fflush(stdout);
	if (dup2(saved_stdout, STDOUT_FILENO) < 0)
		return (perror("dup2 restore"), close(fd), close(saved_stdout), 1);
	printf("Back to screen\n");

	close(fd);
	close(saved_stdout);
	return (0);
}