/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:40:58 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 09:40:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	duo_dup2(t_pipex *px, int i)
{
	if (i == 0)
	{
		dup2(px->in_fd, STDIN_FILENO);
		dup2(px->pipes[1], STDOUT_FILENO);
	}
	else if (i == px->argc - 2)
	{
		px->out_fd = open(px->argv[px->argc - 1], O_WRONLY);
		
		dup2(px->pipes[px->pipes_size - 1], STDIN_FILENO);
		dup2(px->out_fd, STDOUT_FILENO);
	}
	else
	{
		dup2(px->pipes[2 * i - 2], STDIN_FILENO);
		dup2(px->pipes[2 * i - 1], STDOUT_FILENO);
	}
}

void	child(t_pipex *px)
{
	int	i;

	i = -1;
	while (++i < px->cmds_num)
	{
		px->pid = fork();
		if (pipe(px->pipes[2 * i]) < 0)
			child_exit(px);
		if (px->pid == 0)
		{
			
		}
	}
}