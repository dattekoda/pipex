#include <stdio.h>
int	main(void)
{
	char buf[BUFFER_SIZE + 1];

	int	fd = open("infile", O_RDONLY);
	int rd = read(fd, buf, BUFFER_SIZE);
	buf[rd] = '\0';
	printf("\nrd = %d\n", rd);
	write(1, buf, rd);
	rd = read(fd, buf, BUFFER_SIZE);
	buf[rd] = '\0';
	printf("\nrd = %d\n", rd);
	write(1, buf, rd);
	rd = read(fd, buf, BUFFER_SIZE);
	buf[rd] = '\0';
	printf("\nrd = %d\n", rd);
	write(1, buf, rd);
	printf("%zu", ft_strlen(buf));
	close(fd);
	return (0);
}