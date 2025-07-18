/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:05:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 13:31:51 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	err(char *err_str, int status)
{
	ft_putendl_fd(err_str, STDERR_FILENO);
	exit(status);
}

void	exit_pipex(t_pipex *px, char *err_str, int status)
{
	perror(err_str);
	free_pipex(px);
	exit(status);
}
