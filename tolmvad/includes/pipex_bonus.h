#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"

# define ERR_INPUT "Invalid number of arguments.\n"

typedef struct s_ppxb
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx
}	t_ppxb;

//pipex_bonus.c
void	close_pipes(t_ppxb *pipex);

//free_bonus.c
void	parent_free(t_ppxb *pipex);

//here_doc_bonus.c
int	args_in(char *arg, t_ppxb *pipex);

#endif