/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:00:42 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 11:31:50 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**find_paths(char *envp[])
{
	char	**paths;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	paths = ft_split(*envp + 5 ,':');
	return (paths);
}

static void	close_pipes(t_pipex pipex)
{
	close(pipex.tube[0]);
	close(pipex.tube[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex.outfile < 0)
		msg_error(ERR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		msg_error(ERR_PIPE);
	pipex.cmd_paths = find_paths(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == IS_CHILD)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == IS_CHILD)
		second_child(pipex, argv, envp);
	close_pipes(pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (parent_free(&pipex), SUCCESS);
}