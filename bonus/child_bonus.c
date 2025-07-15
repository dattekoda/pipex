/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:40:58 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 16:08:16 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	manage_dup2(t_pipex *px, int i);
static void	manage_pipe(t_pipex *px, int i);
static void	open_output(t_pipex *px);
static void	wait_child(t_pipex *px, int i);

void	child_pipex(t_pipex *px)
{
	int	i;

	i = -1;
	while (++i < px->cmds_num)
	{
		manage_pipe(px, i);
		px->pid = fork();
		if (px->pid == 0)
		{
			if (i == px->cmds_num - 1)
				open_output(px);
			manage_dup2(px, i);
			if (execve(px->cmd[i].path, px->cmd[i].argv, px->input->envp) < 0)
				exit_child(px, ERR_EXECVE, 1);
		}
		else
			wait_child(px, i);
	}
	close_child(px);
}

static void	manage_dup2(t_pipex *px, int i)
{
	if (i == 0)
	{
		dup2(px->in_fd, STDIN_FILENO);
		dup2(px->pipes[1], STDOUT_FILENO);
		close(px->pipes[0]);
	}
	else if (i == px->cmds_num - 1)
	{
		dup2(px->pipes[px->pipes_size - 2], STDIN_FILENO);
		dup2(px->out_fd, STDOUT_FILENO);
		close(px->pipes[px->pipes_size - 1]);
	}
	else
	{
		dup2(px->pipes[2 * i - 2], STDIN_FILENO);
		dup2(px->pipes[2 * i + 1], STDOUT_FILENO);
		close(px->pipes[2 * i - 1]);
		close(px->pipes[2 * i]);
	}
}

static void	manage_pipe(t_pipex *px, int i)
{
	if (i != px->cmds_num - 1)
		if (pipe(&px->pipes[2 * i]) < 0)
			exit_child(px, ERR_PIPE, 1);
	if (i == 1)
		close(px->in_fd);
}

static void	open_output(t_pipex *px)
{
	px->out_fd = open(px->input->argv[px->input->argc - 1],
			O_WRONLY | O_CREAT | (O_TRUNC) * !(px->here_doc), 644);
	if (px->out_fd == -1)
		exit_child(px, ERR_OPEN, 1);
}

static void	wait_child(t_pipex *px, int i)
{
	if (i != px->cmds_num - 1)
		close(px->pipes[2 * i + 1]);
	if (i != 0)
		close(px->pipes[2 * i - 2]);
}
