/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:35:49 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 09:42:34 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	perror(err);
	return (1);
}

void	err_msg(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
	exit(1);
}

void	exit_parent(t_pipex *px, char *err)
{
	free_parent(px);
	exit(msg(err));
}

void	exit_child(t_pipex *px, char *err)
{
	free_child(px);
	exit(msg(err));
}
