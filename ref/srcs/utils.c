/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:16:28 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 16:23:44 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_pipex(t_pipex *px, int argc, char *argv[], char *envp[])
{
	t_input	input;

	if (argc != 5)
		err(ERR_INPUT, FAILURE);
	px->input = &input;
	px->input->argc = argc;
	px->input->argv = argv;
	px->input->envp = envp;
	px->cmds_num = 2;
	px->cmd = NULL;
	px->pid = -1;
}

void	free_split(char **sp)
{
	char	**_sp;

	_sp = sp;
	while (*_sp)
		free(*_sp++);
	free(sp);
}

// char	**get_argv(char *str)
// {
// }