/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:35:00 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 11:30:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	msg(char *err)
{
	ft_putstr_fd(err, STDERR_FILENO);
	return (FAILURE);
}

void	msg_error(char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
}
