#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/includes/libft.h"

# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_HEREDOC "here_doc"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "environment"
# define ERR_CMD "Command not found: "

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
	int		idx;
}	t_ppxb;

//pipex_bonus.c
void	close_pipes(t_ppxb *pipex);

//free_bonus.c
void	parent_free(t_ppxb *pipex);
void	child_free(t_ppxb *pipex);
void	pipe_free(t_ppxb *pipex);

//here_doc_bonus.c
int		args_in(char *arg, t_ppxb *pipex);
void	here_doc(char *argv, t_ppxb *pipex);

//error_bonus.c
int		msg(char *err);
void	msg_pipe(char *arg);
void	msg_error(char *err);

//files_bonus.c
char	*find_path(char **envp);
void	get_infile(char **argv, t_ppxb *pipex);
void	get_outfile(char *argv, t_ppxb *pipex);

//child_bonus.c
void	child(t_ppxb p, char **argv, char **envp);

#endif