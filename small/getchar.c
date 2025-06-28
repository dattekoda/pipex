#include "small.h"

int	ft_getchar(int fd)
{
	static	t_data data = {.n = 0};

	if (data.n == 0)
	{
		data.n = read(fd, data.buf, sizeof(data.buf));
		if (data.n < 0)
			return (READ_ERROR);
		data.bufp = data.buf;
	}
	if (data.n-- >= 0)
		return (*data.bufp++);
	return (EOF);
}

int	ft_putc(t_string *s, char c)
{
	char	*tmp;

	if (s->len + 1 > s->capa)
	{
		s->capa *= 2;
		tmp = malloc(s->capa + 1);
		if (!tmp)
			return (1);
		s->str[s->len] = '\0';
		ft_memcpy(tmp, s->str, s->len);
		free(s->str);
		s->str = tmp;
	}
	s->str[s->len++] = c;
	return (0);
}

// int	main(void)
// {
// 	t_string	s;
// 	int			fd;
// 	int			get;
// 	int			wr;

// 	s.capa = BUFSIZE;
// 	s.len = 0;
// 	s.str = malloc(s.capa + 1);
// 	if (!s.str)
// 		return (perror("malloc"), 1);
// 	fd = open("infile", O_RDONLY);
// 	while (1)
// 	{
// 		get = ft_getchar(fd);
// 		if (get == READ_ERROR)
// 			return (perror("read"), close(fd), free(s.str), 1);
// 		else if (get == EOF)
// 			break ;
// 		ft_putc(&s, get);
// 	}
// 	wr = write(1, s.str, s.len);
// 	if (wr < 0)
// 		return (perror("write"), close(fd), free(s.str), 1);
// 	return (close(fd), free(s.str), 1);
// }
