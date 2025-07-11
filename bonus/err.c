#include "pipex.h"

int	msg(char *err)
{
	perror(err);
	return (1);
}