/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:40:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/17 19:48:37 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	px;
	t_input	input;

	if (argc < args_num(argv[1], &px))
		err(ERR_INPUT, FAILURE);
	px.input = &input;
	init_pipex(&px, argc, argv, envp);
	child_pipex(&px);
	free_pipex(&px);
	return (px.status);
}
