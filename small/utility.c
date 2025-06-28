#include "small.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**get_command(char *str, char *add, int c)
{
	char	**list;
	char	*new;
	size_t	total_len;
	size_t	len2;

	len2 = ft_strlen(str);
	total_len = ft_strlen(add) + len2 + 2;
	new = ft_calloc(total_len, sizeof(char));
	if (!new)
		return (perror("ft_calloc"), NULL);
	ft_memcpy(new, str, len2);
	ft_strlcat(new, " ", total_len);
	ft_strlcat(new, add, total_len);
	list = ft_split(new, c);
	free(new);
	if (!list)
		return (perror("ft_split"), NULL);
	return (list);
}

char	*get_path(char *command)
{
	char	*path;
	size_t	path_len;

	path_len = BINLEN + ft_strlen(command) + 1;
	path = ft_calloc(path_len, sizeof(char));
	if (!path)
		return (NULL);
	ft_memcpy(path, "/bin/", 5);
	ft_strlcat(path, command, path_len);
	return (path);
}
