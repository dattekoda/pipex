/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:20:38 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 16:25:32 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_split(char *argv[])
{
	char	**start;

	start = argv;
	while (*argv)
		free(*argv++);
	free(start);
}

void	parent_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex->pid);
	free_split(pipex->cmd_paths);
}

void	child_free(t_pipex *pipex)
{
	free_split(pipex->cmd_args);
}
