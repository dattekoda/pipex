#include "pipex.h"

static void	get_here_doc(t_pipex *px)
{
	char	*line;
	int		gnl;
	int		fd;

	gnl = 1;
	px->limiter = px->argv[2];
	fd = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0000644);
	while (gnl > 0)
	{
		gnl = ft_get_next_line(STDIN_FILENO, &line);
		if (gnl < 0)
			err_msg("gnl");
		if (!ft_strncmp(px->limiter, line, ft_strlen(px->limiter)))
			break ;
		write(fd, line, sizeof(line));
		free(line);
	}
	if (line)
		free(line);
}

static	void get_cmds(t_pipex *px)
{
	if (px->here_doc)
		get_here_doc(px);
}

void	init_pipex(t_pipex *px)
{
	get_cmds(px);
}