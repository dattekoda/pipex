#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	px;

	init_pipex(&px, argc, argv, envp);
	parse_commands(&px, argv, px.mode + 2);
	create_pipes(&px);
	launch_children(&px);
	
}