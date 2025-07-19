/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:17:14 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/11 15:40:33 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 42
// #endif

// typedef struct s_gnl
// {
// 	char		*str;
// 	ptrdiff_t	head;
// 	ptrdiff_t	tail;
// }	t_gnl;

static int	free_return(char **str, int output)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (output);
}

static int	find_nl(t_gnl *gnl)
{
	if (gnl->str)
	{
		while (gnl->str[++(gnl->tail)])
			if (gnl->str[gnl->tail] == '\n')
				return (1);
	}
	else
	{
		gnl->str = ft_strdup("");
		if (!gnl->str)
			return (1);
	}
	return (0);
}

static int	read_to_str(int fd, t_gnl *gnl)
{
	int		rd;
	char	*tmp;
	char	*buf;

	rd = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_return(&gnl->str, -2));
	while (!find_nl(gnl) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (free(buf), free_return(&gnl->str, -1));
		buf[rd] = '\0';
		tmp = gnl->str;
		gnl->str = ft_strjoin(tmp, buf);
		free(tmp);
		if (!gnl->str)
			return (free_return(&buf, -2));
	}
	if (!gnl->str)
		return (free_return(&buf, -2));
	return (free_return(&buf, rd));
}

static char	*get_line(t_gnl *gnl)
{
	char	*line;

	line = ft_strndup(gnl->str + gnl->head, gnl->tail - gnl->head + 1);
	gnl->head = gnl->tail + 1;
	return (line);
}

int	ft_get_next_line(int fd, char **line)
{
	static t_gnl	gnl = {NULL, 0, -1};
	int				rd;

	rd = read_to_str(fd, &gnl);
	if (rd < 0)
		return (rd);
	*line = get_line(&gnl);
	if (!gnl.str[gnl.head])
	{
		gnl.head = free_return(&gnl.str, 0);
		gnl.tail = -1;
		if (rd == 0)
			return (0);
	}
	return (1);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(int argc, char *argv[])
// {
// 	char	*line;
// 	int		gnl;
// 	int		fd;
// 	if (argc != 2)
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	gnl = 1;
// 	while (gnl > 0)
// 	{
// 		gnl = ft_get_next_line(fd, &line);
// 		if (gnl < 0)
// 			break ;
// 		printf("gnl = %d\n%s", gnl, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
