#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char *av[], char *ep[])
{
	pid_t	pid;
	int		status;

	if (ac < 2)
		return (1);
	(void)av;
	pid = fork();
	if (pid == 0)
	{
		printf("child processe pid: %d\n", getpid());
		execve("/bin/date", av + 1, ep);
	}
	waitpid(pid, &status, 0);
	printf("terminette value %d\n", WEXITSTATUS(status));
	return (WEXITSTATUS(status));
}
