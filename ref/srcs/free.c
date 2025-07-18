/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:29:20 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 16:15:08 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_pipex(t_pipex *px)
{
	int	i;

	close(px->in_fd);
	close(px->out_fd);
	i = -1;
	while (px->cmd && ++i < px->cmds_num)
	{
		free_split(px->cmd[i].argv);
		free(px->cmd[i].path);
	}
}