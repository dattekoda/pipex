#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("not_exist_file.txt", O_RDONLY);
	if (fd == -1)
		printf("Error opening file: %s\n", strerror(errno));
	return (0);
}