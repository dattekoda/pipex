#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define ERR_INPUT "Invalid number of arguments.\n"

typedef struct s_cmd
{
	char	**argv;
	char	*path;
}	t_cmd;

typedef struct s_pipex
{
	int		here_doc; //1: on 0: off
	int		cmd_count; //here_doc :may change
	int		*pipes; //2 * (cmd_count - 1)
	int		*infile;
	int		*outfile;
	char	*limiter;
	t_cmd	*cmd; //malloc
	char	**envp;
	char	**argv;
	pid_t	pid;
}	t_pipex;

int		msg(char *err);
void	err_msg(char *err);
void	init_pipex(t_pipex *px);

#endif