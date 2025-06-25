#include <unistd.h>

int	main(void)
{
	char *argv[] = { "ls", "-l", NULL };
	char *envp[] = { NULL };

	execve("/bin/ls", argv, envp);

	return (0);
}