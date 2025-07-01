/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:00:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 16:33:09 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	**find_paths(char *envp[])
{
	char	**paths;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	paths = ft_split(*envp + 5, ':');
	return (paths);
}

static void	close_pipes(t_pipex pipex)
{
	close(pipex.tube[0]);
	close(pipex.tube[1]);
}

static void	wait_all(t_pipex pipex)
{
	int	i;

	i = -1;
	while (++i < pipex.pid_size)
		waitpid(pipex.pid[i], NULL, 0);
}

static void	ready(int argc, char *argv[], char *envp, t_pipex *pipex)
{
	pipex->pid_size = argc - 3;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		msg_error(ERR_INFILE);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile < 0)
		msg_error(ERR_OUTFILE);
	pipex->cmd_paths = find_paths(envp);
	if (pipe(pipex->tube) < 0)
		msg_error(ERR_PIPE);
	if (pipe(pipex->_tube) < 0)
		msg_error(ERR_PIPE);
	pipex->pid = malloc(sizeof(int) * pipex->pid_size);
	if (!pipex->pid)
		msg_error(ERR_MALLOC);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;

	i = 2;
	if (argc < 5)
		return (msg(ERR_INPUT));
	ready(argc, argv, envp, &pipex);
	pipex.pid[0] = fork();
	if (pipex.pid == IS_CHILD)
		first_child(pipex, argv[i], envp);
	while (++i < argc - 2)
	{
		pipex.pid[i - 3] = fork();
		if (pipex.pid[i - 3] == IS_CHILD && i % 2 == 1)
			middle_child(pipex, argv[i], envp);
		else if (pipex.pid[i - 2] == IS_CHILD && i % 2 == 0)
			_middle_child(pipex, argv[i], envp);
	}
	pipex.pid[i - 3] = fork();
	if (pipex.pid == IS_CHILD)
		last_child(pipex, argv[argc - 1], envp);
	close_pipes(pipex);
	wait_all(pipex);
	return (parent_free(&pipex), SUCCESS);
}
