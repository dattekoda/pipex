#include "pipex.h"

static int	args_num(char *arg, t_pipex *px)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		px->here_doc = 1;
		return (6);
	}
	px->here_doc = 0;
	return (5);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	px;

	if (argc < args_num(argv[1], &px))
		return (msg(ERR_INPUT));
	return (0);
}
