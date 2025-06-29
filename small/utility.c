#include "small.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

// char	**join_cmd_operand(char *cmd, char *operand)
// {
// 	char	**list;
// 	char	*new;
// 	char	*_new;
// 	size_t	total_len;
// 	size_t	len2;

// 	_new = ft_strjoin(cmd, " ");
// 	new = ft_strjoin(_new, operand);
// 	free(_new);
// 	list = ft_split(new, ' ');
// 	free(new);
// 	if (!list)
// 		return (perror("ft_split"), NULL);
// 	return (list);
// }

void	free_cmd(t_cmd *cmd)
{
	if (cmd->args1)
		free_split(cmd->args1);
	if (cmd->args2)
		free_split(cmd->args2);
	if (cmd->path1)
		free(cmd->path1);
	if (cmd->path2)
		free(cmd->path2);
	free(cmd);
}
