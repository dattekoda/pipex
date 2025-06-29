#ifndef SMALL_H
# define SMALL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"
# define FAILURE 1
# define SUCCESS 0
# define BINLEN 5

typedef struct s_cmd
{
	char	**args1;
	char	*path1;
	char	**args2;
	char	*path2;
}	t_cmd;

void	free_cmd(t_cmd *cmd);
void	free_split(char **split);
// char	**join_cmd_operand(char *cmd, char *operand);
char	*get_path(char *cmdline, char **envp);
int		command(t_cmd *cmd, char *argv[], char *envp[]);

#endif