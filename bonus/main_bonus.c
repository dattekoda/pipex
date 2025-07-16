/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:40:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/16 11:09:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	px;
	t_input	input;

	if (argc < args_num(argv[1], &px))
		err_msg(ERR_INPUT);
	px.input = &input;
	init_pipex(&px, argc, argv, envp);
	child_pipex(&px);
	free_parent(&px);
	return (0);
}
