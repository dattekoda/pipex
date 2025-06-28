#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("R_OK: %d\nW_OK: %d\nX_OK: %d\nF_OK: %d\n", R_OK, W_OK, X_OK, F_OK);
	if (argc != 1)
		return (1);
	if (access("output.txt", R_OK) == 0)
		write(1, "OK", 2);
	else
		perror("KO");
	return (0);
}