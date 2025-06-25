#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 1)
		return (1);
	if (access(argv[1], R_OK) == 0)
		write(1, "OK", 2);
	else
		perror("access");
	return (0);
}