/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:40:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 10:18:10 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex(int argc, char *argv[], char *envp[])
{
	t_pipex	px;

	init_pipex(&px, argc, argv, envp);
	child_pipex(&px);
	free_pipex(&px);
	return (px.status);
}
