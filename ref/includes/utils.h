/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:50:12 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 00:20:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "pipex.h"
# include <sys/wait.h>
# include <fcntl.h>

# define FAILURE 1
# define ERRNO_CMD 127

# define ERR_INPUT "Invalid number of arguments."
# define ERR_MALLOC "malloc"
# define ERR_CMD "command not found"
# define ERR_PIPE "pipe"

// void	exec_pipex(t_pipex *px);
void	free_pipex(t_pipex *px);

//err.c
void	err(char *err_str, int status);
void	exit_pipex(t_pipex *px, char *err_str, int status);

//exec.c
void	exec(t_pipex *px);

//utils.c
void	init_pipex(t_pipex *px, int argc, char *argv[], char *envp[]);
void	free_split(char **sp);

//set_pipex.c
void	set_pipex(t_pipex *px);


#endif