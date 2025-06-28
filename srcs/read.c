#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

int	main(void)
{
	int	fd = open("infile", O_RDONLY);
	char	buf[42];

	read(fd, )
}