#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int	gnl = 1;

	while (gnl > 0)
	{
		gnl = ft_get_next_line(0, &line);
		if (gnl < 0)
			return (1);
		if (!ft_strncmp(line, "eof\n", 4))
			break ;
		printf("gnl = %d\n", gnl);
		write(1, line, ft_strlen(line));
		free(line);
	}
	if (line)
		free(line);
	return (0);
}
