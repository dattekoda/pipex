/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:10:39 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 16:24:28 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../../libft/includes/libft.h"
# include "../../gnl/get_next_line.h"

# define FAILURE 1
# define SUCCESS 0
# define IS_CHILD 0
# define ERR_INPUT "Invalid number of arguments\n"
# define ERR_INFILE "Infile Error"
# define ERR_OUTFILE "Outfile Error"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"
# define ERR_MALLOC "malloc"
# define ERR_DUP2 "dup2"

typedef struct s_pipex
{
	pid_t	*pid;
	int		tube[2];
	int		_tube[2];
	int		pid_size;
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	**cmd_args;
	char	*path;
}	t_pipex;

//child_bonus.c
void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	last_child(t_pipex pipex, char *argv[], char *envp[]);
void	middle_child(t_pipex pipex, char *argv, char *envp[]);
void	_middle_child(t_pipex pipex, char *argv, char *envp[]);



//error_bonus.c
void	msg_error(char	*err);
int		msg(char *err);

//free_bonus.c
void	free_split(char *argv[]);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);

#endif