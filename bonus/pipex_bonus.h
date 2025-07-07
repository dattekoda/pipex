#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_cmd
{
	char	**av;
	char	*path;
}	t_cmd;

typedef struct s_pipex
{
	int		mode;
	int		cmd_count;
	int		**pipes;
	int		in_fd; //受け取るファイルのfd
	int		out_fd; //出力するファイルのfd
	char	*limiter;
	t_cmd	*cmds;
	char	**envp;
	pid_t	*pipes;
}	t_pipex;

int		pipex_init(t_pipex *px, int ac, char *av[], char *ep[]);
int		parse_commands(t_pipex *px, char *av[], int first_cmd_i);
int		resolve_path(t_cmd *cmd, char *ep[]);
int		open_input(t_pipex *px, const char *file);
int 	open_output(t_pipex *px, const char *file);
int		here_doc_input(t_pipex *px, const char *limiter);
int		create_pipes(t_pipex *px);
void	select_fd(const t_pipex *px, int idx);
void	child_exec(t_pipex *px, int idx);
int		launch_children(t_pipex *px);
int		wait_children(t_pipex *px);
void	free_pipex(t_pipex *px);
void	error_exit(t_pipex *px, char *msg);

#endif