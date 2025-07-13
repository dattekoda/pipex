#include "pipex.h"

int	msg(char *err)
{
	perror(err);
	return (1);
}

void	err_msg(char *err)
{
	ft_putendl_fd(err, 2);
	exit(1);
}