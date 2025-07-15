/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:45:57 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/15 14:29:05 by khanadat         ###   ########.fr       */
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

// int	main(void)
// {
// 	char	str[100] = "hello this is from khanadat";
// 	char	**sp;

// 	sp = ft_split(str, ' ');
// 	free_split(sp);
// 	return (0);
// }