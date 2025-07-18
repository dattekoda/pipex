/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:35:49 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 10:18:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	err(char *err, int status)
{
	ft_putendl_fd(err, STDERR_FILENO);
	exit(status);
}

int	msg(char *err, int status)
{
	perror(err);
	return (status);
}

void	exit_parent(t_pipex *px, char *err, int status)
{
	if (status == NOT_FOUND)
	{
		ft_putstr_fd(ERR_CMD_NOT_FOUND, STDERR_FILENO);
		ft_putendl_fd(err, STDERR_FILENO);
	}
	else
		perror(err);
	free_pipex(px);
	exit(status);
}

void	exit_child(t_pipex *px, char *err, int status)
{
	close_child(px);
	free_pipex(px);
	exit(msg(err, status));
}
