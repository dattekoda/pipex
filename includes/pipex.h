/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:25:44 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/17 19:48:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define MIN_HERE_DOC_ARGC 6
# define MIN_NORMAL_ARGC 5
# define FAILURE 1
# define ERRNO_CMD_NOT_FOUND 127

# define HERE_DOC_FILE ".here_doc"
# define HERE_DOC "heredoc> "
# define PIPE "pipe "

# define ERR_CMD_NOT_FOUND "command not found: "
# define ERR_INPUT "Invalid number of arguments."
# define ERR_ACCESS "access"
# define ERR_OPEN "open"
# define ERR_CLOSE "close"
# define ERR_MALLOC "malloc"
# define ERR_PIPE "pipe"
# define ERR_EXECVE "execve"
# define ERR_GNL "gnl"

typedef struct s_cmd
{
	char	**argv; //split
	char	*path;
}	t_cmd;

typedef struct s_input
{
	int		argc;
	char	*limiter;
	char	**argv;
	char	**envp;
	char	**argv_cmd; //cmd pointer which starts
}	t_input;

typedef struct s_pipex
{
	t_input	*input;
	bool	here_doc; //1: on 0: off
	int		cmds_num; //here_doc :may change
	int		in_fd;
	int		out_fd;
	int		status;
	int		pipes_size; // 2 * (cmd_count - 1)
	int		*pipes; //malloc
	t_cmd	*cmd; //malloc
	char	*here_doc_file;
	char	*here_doc_msg;
	char	**path_op; //split
	pid_t	pid;
}	t_pipex;

//child_bonus.c
void	child_pipex(t_pipex *px);

//err_bonus.c
void	err(char *err, int status);
int		msg(char *err, int status);
void	exit_parent(t_pipex *px, char *err, int staus);
void	exit_child(t_pipex *px, char *err, int staus);

//free_bonus.c
void	free_pipex(t_pipex *px);
void	close_child(t_pipex *px);

//init_bonus.c
void	init_pipex(t_pipex *px, int argc, char *argv[], char *envp[]);

//utils_bonus.c
void	free_split(char **split);
void	here_doc_msg(t_pipex *px);
int		args_num(char *arg, t_pipex *px);

#endif