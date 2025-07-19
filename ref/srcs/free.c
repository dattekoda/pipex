/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:29:20 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 20:30:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_pipex(t_pipex *px)
{
	int	i;

	safe_close(&px->in_fd);
	safe_close(&px->out_fd);
	free(px->input);
	i = -1;
	while (px->cmd && ++i < px->cmds_num)
	{
		free_split(px->cmd[i].argv);
		free(px->cmd[i].path);
	}
	if (px->cmd)
		free(px->cmd);
}

void	free_split(char **sp)
{
	char	**_sp;

	_sp = sp;
	while (*_sp)
		free(*_sp++);
	free(sp);
}
