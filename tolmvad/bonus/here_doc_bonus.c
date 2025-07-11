/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:49:29 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/11 10:49:30 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	args_in(char *arg, t_ppxb *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	here_doc(char *argv, t_ppxb *pipex)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_RDONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_error(ERR_HEREDOC);
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (ft_get_next_line(STDIN_FILENO, &buf) < 0 || !buf)
			exit(1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv)))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(file);
	pipex->infile = open(".heredoc_tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink(".heredoc_tmp");
		msg_error(ERR_HEREDOC);
	}
}
