#include "../includes/pipex_bonus.h"

static void	creat_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			parent_free(pipex);
		i++;
	}
}

void	close_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ppxb	pipex;

	if (argc < args_in(argv[1], &pipex))//here_doc:6 not:5
		return (msg(ERR_INPUT));
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	
}