#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	if (unlink("a.txt") == -1)
	{
		perror("unlink");
		return (1);
	}
	return (0);
}