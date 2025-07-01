/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:20:38 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/01 10:52:04 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_split(char *argv[])
{
	while (*argv)
		free(*argv++);
	free(argv);
}

void	parent_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free_split(pipex->cmd_paths);
}

void	child_free(t_pipex *pipex)
{
	free_split(pipex->cmd_args);
}