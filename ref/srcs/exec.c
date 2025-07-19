/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:02:14 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 10:59:49 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

typedef struct s_pipe
{
	int	*pipe;
	int	pipe_size;
	int	read_fd;
	int	write_fd;
}	t_pipe;

int		set_pipe(int *pipe_array, int pipe_size);
void	child(t_pipex *px, t_pipe pipe);
void	dup_fd(t_pipex *px, int *pipe_array, int pipe_size, int i);
void	parent(t_pipex *px, int *pipe_array, int pipe_size, int i);

void	exec(t_pipex *px)
{
	int	*pipe_array;
	int	pipe_size;
	int	i;

	pipe_size = (px->cmds_num - 1) * 2;
	pipe_array = (int *)malloc(sizeof(int) * (pipe_size));
	if (!pipe_array)
		exit_pipex(px, ERR_MALLOC, FAILURE);
	if (set_pipe(&pipe_array, pipe_size) < 0)
		exit_pipex(px, ERR_PIPE, FAILURE);
	while (++i < px->cmds_num)
	{
		px->pid = fork();
		if (px->pid == 0)
			child(px, (t_pipe){pipe_array});
		else
			parent(px, pipe_array, pipe_size, i);
	}
	waitpid(px->pid, &px->status, 0);
}

int	set_pipe(int *pipe_array, int pipe_size)
{
	int	i;

	i = -1;
	while (++i < pipe_size)
	{
		if (pipe(&pipe_array[2 * i]) < 0)
		{
			while (0 <= i)
				close(pipe_array[i--]);
			return (-1);
		}
	}
	return (0);
}

void	child(t_pipex *px, t_pipe pipe)
{
	t_cmd	cmd;
	int		j;

	cmd = px->cmd[i];
	dup_fd(px, pipe_array, pipe_size, i);
	j = -1;
	while (++j < pipe_size)
		if (j != 2 * i - 2 && j != 2 * i + 1)
			close(pipe_array[j]);
	if (execve(cmd.path, cmd.argv, px->input->envp) < 0)
		exit_pipex(px, cmd.argv[0], FAILURE);
}

void	dup_fd(t_pipex *px, int *pipe_array, int pipe_size, int i)
{
	if (px->in_fd < 0)
		
	if (i == 0)
	{
		close(px->out_fd);
		dup2(px->in_fd, STDIN_FILENO);
		dup2(pipe_array[1], STDOUT_FILENO);
		return ;
	}
	if (i == px->cmds_num - 1)
	{
		close(px->in_fd);
		dup2(pipe_array[2 * i - 2], STDIN_FILENO);
		dup2(px->out_fd, STDOUT_FILENO);
		return ;
	}
	close(px->in_fd);
	close(px->out_fd);
	dup2(pipe_array[2 * i - 2], STDIN_FILENO);
	dup2(pipe_array[2 * i + 1], STDOUT_FILENO);
}

void	parent(t_pipex *px, int *pipe_array, int pipe_size, int i);