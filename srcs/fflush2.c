#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	FILE *log = fopen("progress.log", "w");

	if (!log) return 1;

	int	i = 0;
	while (i < 10)
	{
		fprintf(log, "step %d/10\n", i + 1);
		fflush(log);
		sleep(1);
		++i;
	}
	fclose(log);
	return (0);
}