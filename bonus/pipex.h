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
	int		here_doc;
	int		cmd_count;
	int		*pipes;
	int		in_fd;
	int		out_fd;
	char	*limiter;
	t_cmd	*cmd;
	char	**envp;
	pid_t	pid;
}	t_pipex;

int	msg(char *err);

#endif