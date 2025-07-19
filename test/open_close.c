#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	fake;

	fd = open("pipe.c", O_RDONLY);
	fake = 10;
	printf("fake=%d: close = %d\n", fake, close(fake));
	printf("fd=%d: close = %d\n", fd, close(fd));
	return (0);
}