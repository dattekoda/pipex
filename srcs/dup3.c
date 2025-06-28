#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd = open("ohayo.txt", O_WRONLY | O_APPEND);

	if (fd < 0)
		return (perror("open"), -1);
	int	new_fd = dup(fd);
	if (new_fd < 0)
		return (perror("dup"), close(fd), -1);
	printf("old:%d\nnew:%d\n", fd, new_fd);
	write(new_fd, "Hello, World!", 13);
	return (close(fd), close(new_fd), 0);
}
