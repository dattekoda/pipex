/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:40:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 15:04:41 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	args_num(char *arg, t_pipex *px)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		px->here_doc = 1;
		return (6);
	}
	px->here_doc = 0;
	return (5);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	px;
	t_input	input;

	if (argc < args_num(argv[1], &px))
		return (msg(ERR_INPUT, 1));
	px.input = &input;
	init_pipex(&px, argc, argv, envp);
	child_pipex(&px);
	free_parent(&px);
	return (0);
}
