/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:49:44 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 16:07:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pipex(int argc, char *argv[], char *envp[])
{
	t_pipex	px;

	init_pipex(&px, argc, argv, envp);
	set_pipex(&px);
	// exec_pipex(&px);
	free_pipex(&px);
	return (0);
}