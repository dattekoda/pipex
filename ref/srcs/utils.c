/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:16:28 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 21:25:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_pipex(t_pipex *px, int argc, char *argv[], char *envp[])
{
	t_input	*input;

	if (argc != 5)
		err(ERR_INPUT, FAILURE);
	input = (t_input *)malloc(sizeof(t_input));
	if (!input)
		err(ERR_MALLOC, FAILURE);
	px->input = input;
	px->input->argc = argc;
	px->input->argv = argv;
	px->input->envp = envp;
	px->in_fd = -1;
	px->out_fd = -1;
	px->cmds_num = 2;
	px->cmd = NULL;
	px->pid = -1;
}

int	safe_close(int *fd)
{
	if (*fd < 0)
		return (0);
	if (close(*fd) < 0)
	{
		perror("safe close");
		return (-1);
	}
	*fd = -1;
	return (0);
}

int	close_pipe(int *arr)
{
	if (safe_close(arr) || safe_close(arr + 1))
		return (-1);
	return (0);
}

void	set_exec(t_pipex *px, int *size, int **arr, pid_t **pid_arr)
{
	*size = (px->cmds_num - 1) * 2;
	*arr = (int *)ft_calloc(*size, sizeof(int));
	if (!*arr)
		exit_pipex(px, ERR_MALLOC, FAILURE);
	*pid_arr = (pid_t *)ft_calloc(px->cmds_num, sizeof(size_t));
	if (!*pid_arr)
		exit_pipex(px, ERR_MALLOC, FAILURE);
}