/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:29:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 10:25:29 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

typedef struct s_input
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_input;

typedef struct s_cmd
{
	char	**argv; //split
	char	*path; //malloc
}	t_cmd;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		cmds_num;
	int		status;
	t_input	*input;
	t_cmd	*cmd;
	pid_t	pid;
}	t_pipex;

int	pipex(int argc, char *argv[], char *envp[]);

#endif