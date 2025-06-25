#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("Tell me your name:");
	// fflush(stdout);
	char	name[32] = {0};
	fgets(name, sizeof(name), stdin);
	printf("hello, %s", name);
	return (0);
}