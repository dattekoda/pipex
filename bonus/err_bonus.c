/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:35:49 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 13:49:55 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err, int status)
{
	perror(err);
	return (status);
}

void	err_msg(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
	exit(1);
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
