/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:33:34 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/16 16:26:31 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_stdin(t_pipex *px, char **argv);
static void	get_path(t_pipex *px);
static void	get_cmds(t_pipex *px);
static void	ready_init(t_pipex *px, int argc, char *argv[], char *envp[]);

void	init_pipex(t_pipex *px, int argc, char *argv[], char *envp[])
{
	ready_init(px, argc, argv, envp);
	get_cmds(px);
	get_path(px);
}

static void	get_stdin(t_pipex *px, char **argv)
{
	char	*line;
	int		gnl;

	gnl = 1;
	px->input->limiter = argv[2];
	px->in_fd = open(HERE_DOC_FILE, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (px->in_fd < 0)
		exit(msg(ERR_OPEN, FAILURE));
	here_doc_msg(px);
	while (gnl > 0)
	{
		ft_putstr_fd(px->here_doc_msg, STDOUT_FILENO);
		gnl = ft_get_next_line(STDIN_FILENO, &line);
		if (gnl < 0)
			msg(ERR_GNL, FAILURE);
		if (!ft_strncmp(px->input->limiter, line, ft_strlen(line) - 1))
			break ;
		ft_putstr_fd(line, px->in_fd);
		free(line);
	}
	if (close(px->in_fd) < 0)
		exit_parent(px, ERR_CLOSE, FAILURE);
	if (line)
		free(line);
}

static void	get_path(t_pipex *px)
{
	char	*path;
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	while (++j < px->cmds_num)
	{
		i = -1;
		while (px->path_op[++i])
		{
			tmp = ft_strjoin(px->path_op[i], "/");
			path = ft_strjoin(tmp, px->cmd[j].argv[0]);
			if (!(free(tmp), access(path, X_OK)))
			{
				px->cmd[j].path = path;
				break ;
			}
			free(path);
		}
		if (!px->cmd[j].path)
			exit_parent(px, px->cmd[j].argv[0], NOT_FOUND);
	}
}

static void	get_cmds(t_pipex *px)
{
	int	i;

	px->cmd = malloc(px->cmds_num * sizeof(t_cmd));
	px->pipes_size = 2 * (px->cmds_num - 1);
	if (px->pipes_size)
		px->pipes = malloc(sizeof(int) * px->pipes_size);
	if (!px->cmd || !px->pipes)
		exit_parent(px, ERR_MALLOC, FAILURE);
	i = -1;
	while (++i < px->cmds_num)
	{
		px->cmd[i].argv = ft_split(px->input->argv_cmd[i], ' ');
		if (!px->cmd[i].argv)
			exit_parent(px, ERR_MALLOC, FAILURE);
	}
}

static void	ready_init(t_pipex *px, int argc, char *argv[], char *envp[])
{
	px->input->argc = argc;
	px->input->argv = argv;
	px->input->envp = envp;
	px->input->argv_cmd = argv + px->here_doc + 2;
	px->cmds_num = argc - 3 - px->here_doc;
	if (px->here_doc)
		get_stdin(px, argv);
	px->path_op = NULL;
	while (*envp)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
		{
			px->path_op = ft_split(*envp + 5, ':');
			break ;
		}
		envp++;
	}
	if (!px->path_op)
		exit_parent(px, ERR_MALLOC, 1);
}
