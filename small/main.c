#include "small.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**command;
	char	*path;

	if (argc < 3)
		return (perror("argc"), 1);
	command = get_command(argv[2], argv[1], ' ');
	if (!command)
		return (1);
	path = get_path(command[0]);
	if (!path)
		return (perror("get_path"), free_split(command), 1);
	execve(path, command, envp);
	return (free_split(command), free(path), 0);
}
