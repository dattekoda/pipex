#include "small.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (argc < 5)
		return (perror("usage"), 1);
	cmd->path1 = get_path(argv[2], envp);
	if (!cmd->path1)
		return (perror("command not found"), free(cmd), 127);
	cmd->args1 = ft_split(argv[2], ' ');
	if (!cmd->args1)
		return (perror("cannot join"), free_cmd(cmd), 1);
	cmd->path2 = get_path(argv[3], envp);
	if (!cmd->path2)
		return (perror("command not found"), free_cmd(cmd), 127);
	cmd->args2 = ft_split(argv[3], ' ');
	if (!cmd->args2)
		return (perror("cannot join"), free_cmd(cmd), 1);
	if (command(cmd, argv, envp))
		return (perror("no option"), free_cmd(cmd), 1);
	return (free_cmd(cmd), 0);
}
