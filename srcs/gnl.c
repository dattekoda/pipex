#include "../libft/includes/libft.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	// fd = open(argv[1], O_RDONLY);
	// if (fd < 0)
	// 	return (-1);
	int	gnl = 1;

	while (gnl > 0)
	{
		gnl = ft_get_next_line(0, &line);
		if (gnl < 0)
			break ;
		write(1, line, ft_strlen(line));
		free(line);
	}
	return (0);
}
