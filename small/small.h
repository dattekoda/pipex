#ifndef SMALL_H
# define SMALL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# define BUFSIZE 42
# define READ_ERROR -2
# define FAILURE 1
# define SUCCESS 0
# define BINLEN 5

typedef struct s_data
{
	char	buf[BUFSIZE];
	char	*bufp;
	int		n;
}	t_data;

typedef struct s_string
{
	char	*str;
	size_t	capa;
	size_t	len;
}	t_string;

int		ft_getchar(int fd);
int		ft_putc(t_string *s, char c);
void	free_split(char **split);
char	**get_command(char *str, char *add, int c);
char	*get_path(char *command);

#endif