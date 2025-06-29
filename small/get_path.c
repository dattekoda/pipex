#include "small.h"

//get path from env info
static char	*get_path_line(char **envp)
{
	size_t	i;

	i = -1;
	while (envp && envp[++i])
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
	return (NULL);
}

//get /usr/local/sbin + "/" + command
static char	*join_path_cmd(char *path, char *cmd)
{
	char	*str;
	char	*_str;

	_str = ft_strjoin(path, "/");
	if (!_str)
		return (NULL);
	str = ft_strjoin(_str, cmd);
	free(_str);
	if (!str)
		return (NULL);
	return (str);
}

//find the place where the command is.
static char	*find_cmd_in_path(char *cmd, char **envp)
{
	char	*path_line;
	char	**dirs;
	size_t	i;
	char	*full;

	path_line = get_path_line(envp);
	i = -1;
	full = NULL;
	dirs = ft_split(path_line, ':');
	if (!dirs)
		return (perror("split"), NULL);
	while (dirs[++i] && !full)
	{
		full = join_path_cmd(dirs[i], cmd);
		if (!full)
			break ;
		if (access(full, X_OK) == 0)
			break ;
		free(full);
		full = NULL;
	}
	free_split(dirs);
	return (full);
}

//get argv[2] and return full path like /usr/bin/ls
//also check if the cmdline's already had full path or just return it as is.
char	*get_path(char *cmdline, char **envp)
{
	char	**tokens;
	char	*cmd;
	char	*full_path;

	tokens = ft_split(cmdline, ' ');
	if (!tokens)
		return (NULL);
	cmd = tokens[0];
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			full_path = ft_strdup(cmd);
		else
			full_path = NULL;
	}
	else
		full_path = find_cmd_in_path(cmd, envp);
	return (free_split(tokens), full_path);
}
