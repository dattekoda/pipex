/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:45:57 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/16 11:23:02 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
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

//count min_argc 
int	args_num(char *arg, t_pipex *px)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		px->here_doc = 1;
		if (!access(HERE_DOC_FILE, F_OK))
			unlink(HERE_DOC_FILE);
		return (MIN_HERE_DOC_ARGC);
	}
	px->here_doc = 0;
	return (MIN_NORMAL_ARGC);
}

// //  valgrind cc utils_bonus.c err_bonus.c free_bonus.c ../libft/libft.a
// int	main(void)
// {
// 	t_pipex px;
// 	t_input	input;

// 	px.input = &input;
// 	px.cmds_num = 4;
// 	here_doc_msg(&px);
// 	printf("%s", px.here_doc_msg);
// 	free(px.here_doc_msg);
// 	return (0);
// }
// int	main(void)
// {
// 	char	str[100] = "hello this is from khanadat";
// 	char	**sp;

// 	sp = ft_split(str, ' ');
// 	free_split(sp);
// 	return (0);
// }