/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:35:49 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/16 14:09:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	free_parent(px);
	exit(msg(err, status));
}

void	exit_child(t_pipex *px, char *err, int status)
{
	close_child(px);
	exit(msg(err, status));
}
