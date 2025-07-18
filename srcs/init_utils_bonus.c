/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:19:45 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 09:25:22 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_path_op(t_pipex *px, char **envp)
{
	int		i;
	char	*tmp;

	while (envp)
		if (!ft_strncmp("PATH=", *envp++, 5))
			break ;
	px->path_op = ft_split(*(--envp) + 5, ':');
	if (!*envp)
		exit_parent(px, ERR_CMD_NOT_FOUND, NOT_FOUND);
	else if (!px->path_op)
		exit_parent(px, ERR_MALLOC, FAILURE);
	i = -1;
	while (px->path_op && px->path_op[++i])
	{
		tmp = ft_strjoin(px->path_op[i], "/");
		if (!tmp)
			exit_parent(px, ERR_MALLOC, FAILURE);
		free(px->path_op[i]);
		px->path_op[i] = tmp;
	}
}

void	here_doc_msg(t_pipex *px)
{
	char	*msg;
	char	*tmp;
	int		i;

	msg = ft_strdup(HERE_DOC);
	i = -1;
	while (msg && ++i < px->cmds_num - 1)
	{
		tmp = msg;
		msg = ft_strjoin(PIPE, msg);
		free(tmp);
	}
	if (!msg)
		exit_parent(px, ERR_MALLOC, FAILURE);
	px->here_doc_msg = msg;
}
