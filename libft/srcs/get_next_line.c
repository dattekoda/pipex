/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:54:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/07/08 16:31:42 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#define BUFFER_SIZE 42

typedef struct	s_gnl
{
	int		rd;
	int		now;
	int		next;
	char	*str;
}	t_gnl;

int	free_error(char *str, int err_no)
{
	if (str)
		free(str);
	return (err_no);
}

char	*get_line(t_gnl gnl)
{
	if (!gnl.str)
		return (NULL);
	if (!gnl.str[gnl.next])
		return (ft_strdup(&gnl.str[gnl.now]));
	return (ft_strndup(&gnl.str[gnl.now], gnl.next - gnl.now + 1));
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	join = ft_strjoin(s1, s2);
	free(s1);
	return (join);
}

//malloc失敗-2、read失敗-1、不正なfdまたはbuffer_size:-3,成功:lineの長さ、EOF:0
int	ft_get_next_line(int fd, char **line)
{
	static t_gnl	gnl = {.rd = 1, .now = 0, .next = 0, NULL};
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-3);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_error(gnl.str, -2));
	while (gnl.rd > 0)
	{
		gnl.rd = read(fd, buf, BUFFER_SIZE);
		if (gnl.rd < 0)
			return (free_error(buf, -1));
		buf[gnl.rd] = '\0';
		gnl.str = gnl_strjoin(gnl.str, buf);
	}
	free(buf);
	while (gnl.str && gnl.str[gnl.next] && gnl.str[gnl.next] != '\n')
		gnl.next++;
	*line = get_line(gnl);
	if (!gnl.str && gnl.rd == 0)
		return (0);
	gnl.now = gnl.next + 1;
	return (1);
}

#include <fcntl.h>
int	main(int argc, char *argv[])
{
	char	*line;

	if (argc != 2)
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	// ft_get_next_line(fd, &line);
	printf("%d\n", ft_get_next_line(fd, &line));
	printf("%s", line);
	free(line);
	printf("%d\n", ft_get_next_line(fd, &line));
	printf("%s", line);
	free(line);
	// while (ft_get_next_line(fd, &line) != 0)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	close(fd);
	return (0);
}
