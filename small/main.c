#include "small.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		get;
	char	*file;
	char	**command;
	char	buf[BUFSIZE];
	t_string	s;

	if (argc != 3)
		return (perror("argc"), FAILURE);
	file = argv[1];
	if (access(file, R_OK))
		return (perror("access"), FAILURE);
	fd = open(argv[1], O_RDONLY);
	s.capa = BUFSIZE;
	s.len = 0;
	s.str = malloc(s.capa);
	if (!s.str)
		return (perror("malloc"), close(fd), FAILURE);
	while (1)
	{
		get = ft_getchar(fd);
		if (get == READ_ERROR)
			return (perror("getchar"), close(fd), free(s.str), FAILURE);
		else if (get == EOF)
			break ;
		ft_putc(&s, get);
	}
	command = ft_split(argv[2], ' ');
	if (!command)
		return (close(fd), perror("split"), free(s.str), FAILURE);
	execve("/bin/ls", command, );
	return (close(fd), free(s.str), SUCCESS);
}
