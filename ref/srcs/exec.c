/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:02:14 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 21:25:52 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	child(t_pipex *px, int *arr, int i);
static void	parent(t_pipex *px, int *arr, int i);
static void	set_fd(t_pipex *px, int *arr, int i);
static void	dup_fd(t_pipex *px, int *arr, int i);

void	exec_pipex(t_pipex *px)
{
	int		size;
	int		i;
	int		*arr;
	pid_t	*pid_arr;

	set_exec(px, &size, &arr, &pid_arr);
	i = -1;
	while (++i < px->cmds_num)
	{
		set_fd(px, arr, i);
		pid_arr[i] = fork();
		if (pid_arr[i] == 0)
			child(px, arr, i);
		else
			parent(px, arr, i);
	}
	i = -1;
	while (++i < px->cmds_num)
		waitpid(pid_arr[i], &px->status, 0);
	free(arr);
	free(pid_arr);
}

static void	child(t_pipex *px, int *arr, int i)
{
	t_cmd	cmd;

	cmd = px->cmd[i];
	if (i != 0 && safe_close(&arr[2 * i - 1]))
		exit_pipex(px, ERR_CLOSE, FAILURE);
	if (i != px->cmds_num - 1 && safe_close(&arr[2 * i]))
		exit_pipex(px, ERR_CLOSE, FAILURE);
	dup_fd(px, arr, i);
	if (execve(cmd.path, cmd.argv, px->input->envp))
		exit_pipex(px, cmd.argv[0], ERRNO_CMD);
}

static void	parent(t_pipex *px, int *arr, int i)
{
	if (i == 0 && safe_close(&px->in_fd))
		exit_pipex(px, ERR_CLOSE, FAILURE);
	if (i != 0 && safe_close(&arr[2 * i - 2]))
		exit_pipex(px, ERR_CLOSE, FAILURE);
	if (i != px->cmds_num - 1 && safe_close(&arr[2 * i + 1]))
		exit_pipex(px, ERR_CLOSE, FAILURE);
	if (i == px->cmds_num - 1 && safe_close(&px->out_fd))
		exit_pipex(px, ERR_CLOSE, FAILURE);
}

static void	set_fd(t_pipex *px, int *arr, int i)
{
	if (i == 0)
		px->in_fd = open(px->input->argv[1], O_RDONLY);
	if (1 < i && close_pipe(&arr[2 * i - 4]))
		exit_pipex(px, ERR_CLOSE, FAILURE);
	if (i != px->cmds_num - 1 && pipe(&arr[2 * i]) < 0)
		exit_pipex(px, ERR_PIPE, FAILURE);
	if (i == px->cmds_num - 1)
		px->out_fd = open(px->input->argv[px->input->argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
}

static void	dup_fd(t_pipex *px, int *arr, int i)
{
	if (i == 0)
	{
		if (dup2(px->in_fd, STDIN_FILENO) == -1 ||
			dup2(arr[1], STDOUT_FILENO) == -1)
			exit_pipex(px, ERR_DUP2, FAILURE);
		if (safe_close(&px->in_fd) || safe_close(&arr[1]))
			exit_pipex(px, ERR_CLOSE, FAILURE);
		return ;
	}
	if (i == px->cmds_num - 1)
	{
		if (dup2(arr[2 * i - 2], STDIN_FILENO) == -1 ||
			dup2(px->out_fd, STDOUT_FILENO) == -1)
			exit_pipex(px, ERR_DUP2, FAILURE);
		if (safe_close(&arr[2 * i - 2]) || safe_close(&px->out_fd))
			exit_pipex(px, ERR_CLOSE, FAILURE);
		return ;
	}
	if (dup2(arr[2 * i - 2], STDIN_FILENO) == -1 ||
		dup2(arr[2 * i + 1], STDOUT_FILENO) == -1)
		exit_pipex(px, ERR_DUP2, FAILURE);
	if (safe_close(&arr[2 * i - 2]) || safe_close(&arr[2 * i + 1]))
		exit_pipex(px, ERR_CLOSE, FAILURE);
}
