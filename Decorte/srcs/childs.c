/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:05:37 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 11:33:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(t_pipex pipex)
{
	size_t	i;
	char	*tmp;
	char	*path;
	char	*cmd;

	i = -1;
	cmd = pipex.cmd_args[0];
	while (pipex.cmd_paths[++i])
	{
		tmp = ft_strjoin(*(pipex.cmd_paths), "/");
		if (!tmp)
			break ;
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path)
			break ;
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	if (dup2(pipex.tube[1], STDOUT_FILENO) < 0)
		exit((close(pipex.tube[0]), msg(ERR_DUP2), EXIT_FAILURE));
	close(pipex.tube[0]);
	if (dup2(pipex.infile, STDIN_FILENO) < 0)
		exit((msg(ERR_DUP2), EXIT_FAILURE));
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (!pipex.cmd_args)
		exit((msg(ERR_MALLOC), EXIT_FAILURE));
	pipex.path = get_path(pipex);
	if (!pipex.path)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipex.path, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
{
	if (dup2(pipex.tube[0], STDIN_FILENO) < 0)
		exit((close(pipex.tube[1]), msg(ERR_DUP2), EXIT_FAILURE));
	close(pipex.tube[1]);
	if (dup2(pipex.outfile, STDOUT_FILENO) < 0)
		exit((msg(ERR_DUP2), EXIT_FAILURE));
	pipex.cmd_args = ft_split(argv[3], ' ');
	if (!pipex.cmd_args)
		exit((msg(ERR_MALLOC), EXIT_FAILURE));
	pipex.path = get_path(pipex);
	if (!pipex.path)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipex.path, pipex.cmd_args, envp);
}