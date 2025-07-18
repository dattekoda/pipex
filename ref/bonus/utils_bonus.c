/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:45:57 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/18 10:18:47 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

//count min_argc
int	args_num(char *arg, t_pipex *px)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		px->here_doc = 1;
		px->here_doc_file = ft_strdup(HERE_DOC_FILE);
		if (!access(px->here_doc_file, F_OK))
			unlink(px->here_doc_file);
		return (MIN_HERE_DOC_ARGC);
	}
	px->here_doc = 0;
	return (MIN_NORMAL_ARGC);
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

// void	get_random_name(t_pipex *px)
// {
// 	char	*name;
// 	char	*tmp;
// 	int		i;

// 	i = INT_MAX;
// 	while (++i != INT_MAX)
// 	{
// 		tmp = ft_strdup(".");
// 		if (!tmp)
// 			break ;
// 		name = ft_strjoin(tmp, ft_itoa(i));
		
// 	}
// }

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