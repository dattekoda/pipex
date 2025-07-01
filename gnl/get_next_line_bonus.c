/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:54:02 by khanadat          #+#    #+#             */
/*   Updated: 2025/06/22 05:49:53 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*for_stash(int fd, char *stash, char *buf, ssize_t *byte)
{
	char	*tmp;

	if (!stash)
		stash = ft_strdup("");
	while (!ft_strchr(stash, '\n') && (*byte) > 0)
	{
		(*byte) = read(fd, buf, BUFFER_SIZE);
		if ((*byte) < 0)
			return (free(stash), free(buf), NULL);
		buf[(*byte)] = '\0';
		if (!stash)
		{
			tmp = ft_strdup((free(buf), buf));
			stash = tmp;
		}
		else
		{
			tmp = ft_strjoin(stash, buf);
			free(stash);
			stash = tmp;
		}
	}
	return (stash);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	byte;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	byte = 1;
	stash = for_stash(fd, stash, buf, &byte);
	if (!stash)
		return (NULL);
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[65534];

	if (fd < 0 || 65534 <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
