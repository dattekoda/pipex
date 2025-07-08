#include "../includes/pipex_bonus.h"

int	msg(char *err)
{
	ft_putstr_fd(err, 2);
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit(1);
}