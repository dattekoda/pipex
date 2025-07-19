/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:59:21 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/19 20:21:26 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	**get_env_path(t_pipex *px);
static void	get_path(t_pipex *px, char **env_path, t_cmd *cmd);
static void	set_cmd(t_pipex *px);

void	set_pipex(t_pipex *px)
{
	set_cmd(px);
}

static void	set_cmd(t_pipex *px)
{
	int		i;
	char	**env_path;

	env_path = NULL;
	env_path = get_env_path(px);
	px->cmds_num = px->input->argc - 3;
	px->cmd = malloc(sizeof(t_cmd) * px->cmds_num);
	i = -1;
	while (px->cmd && ++i < px->cmds_num)
	{
		px->cmd[i].argv = ft_split(px->input->argv[i + 2], ' ');
		if (!px->cmd[i].argv)
			exit_pipex(px, ERR_MALLOC, FAILURE);
		if (!px->cmd[i].argv[0])
			exit_pipex(px, "", ERRNO_CMD);
		get_path(px, env_path, &px->cmd[i]);
	}
	free_split(env_path);
}

static char **get_env_path(t_pipex *px)
{
	int		i;
	char	*tmp;
	char	**path;

	i = -1;
	while (px->input->envp[++i])
		if (!ft_strncmp("PATH=", px->input->envp[i], 5))
			break ;
	path = ft_split(px->input->envp[i] + 5, ':');
	if (!path)
		exit_pipex(px, ERR_MALLOC, FAILURE);
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			exit_pipex(px, ERR_MALLOC, FAILURE);
		free(path[i]);
		path[i] = tmp;
	}
	return (path);
}

static void	get_path(t_pipex *px, char **env_path, t_cmd *cmd)
{
	char	*tmp;
	int		i;

	i = -1;
	while (env_path[++i])
	{
		tmp = ft_strjoin(env_path[i], cmd->argv[0]);
		if (!tmp)
			exit_pipex(px, ERR_MALLOC, FAILURE);
		if (!access(tmp, F_OK))
			break ;
		free(tmp);
	}
	if (!access(tmp, X_OK))
		cmd->path = tmp;
	else
	{
		perror(cmd->argv[0]);
		free(tmp);
	}
}
