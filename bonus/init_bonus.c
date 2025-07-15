/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:33:34 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 14:59:35 by khanadat         ###   ########.fr       */
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
	px->in_fd = open(HERE_DOC_FILE, O_CREAT | O_RDWR | O_TRUNC, 644);
	if (px->in_fd == -1)
		exit(msg(ERR_OPEN, 1));
	while (gnl > 0)
	{
		ft_putstr_fd(HERE_DOC, STDOUT_FILENO);
		gnl = ft_get_next_line(STDIN_FILENO, &line);
		if (gnl < 0)
			err_msg("gnl");
		if (!ft_strncmp(px->input->limiter, line,
				ft_strlen(px->input->limiter)))
			break ;
		ft_putstr_fd(line, px->in_fd);
		free(line);
	}
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
		if (!px->path_op[j])
			exit_parent(px, ERR_ACCESS, 1);
	}
}

static void	get_cmds(t_pipex *px)
{
	int	i;

	px->cmds_num = px->input->argc - 3 - px->here_doc;
	px->cmd = malloc(px->cmds_num * sizeof(t_cmd));
	px->pipes_size = 2 * (px->cmds_num - 1);
	if (px->pipes_size)
		px->pipes = malloc(sizeof(int) * px->pipes_size);
	if (!px->cmd || !px->pipes)
		exit_parent(px, ERR_MALLOC, 1);
	i = -1;
	while (++i < px->cmds_num)
	{
		px->cmd[i].argv = ft_split(px->input->argv_cmd[i], ' ');
		if (!px->cmd[i].argv)
			exit_parent(px, ERR_MALLOC, 1);
	}
}

static void	ready_init(t_pipex *px, int argc, char *argv[], char *envp[])
{
	if (px->here_doc)
		get_stdin(px, argv);
	else
		px->in_fd = open(argv[1], O_RDONLY);
	if (px->in_fd == -1)
		exit(msg(ERR_OPEN, 1));
	px->input->argc = argc;
	px->input->argv = argv;
	px->input->envp = envp;
	px->input->argv_cmd = argv + px->here_doc + 2;
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
