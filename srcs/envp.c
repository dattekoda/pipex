#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	i = 0;

	printf("===Environment Variables===\n");
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}