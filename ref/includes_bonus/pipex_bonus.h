/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:25:44 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 16:04:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>

# define FAILURE 1
# define ERR_INPUT "Invalid number of arguments."

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

int	pipex(int argc, char *argv[], char *envp[]);

#endif