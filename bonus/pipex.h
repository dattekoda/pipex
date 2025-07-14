#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define HERE_DOC_FILE ".here_doc"
# define HERE_DOC ""
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_ACCESS "access"
# define ERR_OPEN "open"
# define ERR_MALLOC "malloc"

typedef struct s_cmd
{
	char	**argv; //split
	char	*path;
}	t_cmd;

typedef struct s_pipex
{
	int		here_doc; //1: on 0: off
	int		cmds_num; //here_doc :may change
	int		in_fd;
	int		out_fd;
	int		pipes_size; // 2 * (cmd_count - 1)
	int		*pipes; //malloc
	char	*limiter;
	t_cmd	*cmd; //malloc
	char	**argv_cmd; //cmd pointer which starts
	char	**path_op; //split
	pid_t	pid;
}	t_pipex;

//err_bonus.c
int		msg(char *err);
void	err_msg(char *err);
void	exit_parent(t_pipex *px, char *err);

//free_bonus.c
void	free_parent(t_pipex *px);

//init_bonus.c
void	init_pipex(t_pipex *px, int argc, char *argv[], char *envp[]);

//utils_bonus.c
void	free_split(char **split);

#endif