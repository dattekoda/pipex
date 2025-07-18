/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:17:10 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 09:23:40 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "pipex.h"

# define MIN_HERE_DOC_ARGC 6
# define MIN_NORMAL_ARGC 5
# define FAILURE 1
# define NOT_FOUND 127

# define HERE_DOC_FILE ".here_doc"
# define HERE_DOC "heredoc> "
# define PIPE "pipe "

# define ERR_CMD_NOT_FOUND "command not found"
# define ERR_INPUT "Invalid number of arguments."
# define ERR_ACCESS "access"
# define ERR_OPEN "open"
# define ERR_CLOSE "close"
# define ERR_MALLOC "malloc"
# define ERR_PIPE "pipe"
# define ERR_EXECVE "execve"
# define ERR_GNL "gnl"

//err_bonus.c
void	err(char *err, int status);
int		msg(char *err, int status);
void	exit_parent(t_pipex *px, char *err, int staus);
void	exit_child(t_pipex *px, char *err, int staus);

//free_bonus.c
void	close_child(t_pipex *px);

//init_utils_bonus.c
void	get_path_op(t_pipex *px, char **envp);
void	here_doc_msg(t_pipex *px);

//utils_bonus.c
int		args_num(char *arg, t_pipex *px);
void	free_split(char **split);

#endif