/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:20:40 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 16:14:07 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_parent(t_pipex *px)
{
	int	i;

	i = -1;
	if (px->path_op)
		free_split(px->path_op);
	if (px->pipes)
		free(px->pipes);
	if (px->cmd)
	{
		i = -1;
		while (++i < px->cmds_num)
		{
			if (px->cmd[i].argv)
				free_split(px->cmd[i].argv);
			if (px->cmd[i].path)
				free(px->cmd[i].path);
		}
		free(px->cmd);
	}
	unlink(HERE_DOC_FILE);
}

void	close_child(t_pipex *px)
{
	int	i;

	i = -1;
	while (++i < px->pipes_size)
		close(px->pipes[i]);
}
