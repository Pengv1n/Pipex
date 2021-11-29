#include "pipex.h"

void	ft_free(char **tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
}

char	**find_path(char **envr)
{
	char	**path;
	int		i;

	path = ((void *)0);
	i = -1;
//	while (envr[++i])
//		printf("%s\n",envr[i]);
	i = -1;
	while (envr[++i])
	{
//		printf("%s\n", envr[i]);
		if (ft_strnstr(envr[i], "PATH=/home", ft_strlen(envr[i])))
		{
			path = ft_split(envr[i] + ft_strlen("PATH="), ':');
			break ;
		}
	}
	if (!envr[i])
		ps_error("Error: no path in envr");
	if (!path)
		ps_error("Error: malloc error (path split)");
	return (path);
}

char	*find_check_cmd(char **path, char *tmp_cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	printf("%s\n", tmp_cmd);
	while (path[++i])
	{
		printf("%s\n", path[i]);
		tmp = ft_strjoin(path[i], tmp_cmd);
		if (!tmp)
			ps_error("Error: malloc error (tmp strjoin)");
		if (access(tmp, F_OK) == 0)
			return (tmp);
		else
			free(tmp);
	}
	return (NULL);
}

char	**find_cmd(char *command, char **envr)
{
	char	**path;
	char	**cmd;
	char	*tmp_cmd;

	path = find_path(envr);
	cmd = ft_split(command, ' ');
	if (!cmd)
		ps_error("Error: malloc error (cmd split)");
	tmp_cmd = ft_strjoin("/", *cmd);
	if (!tmp_cmd)
		ps_error("Error: malloc error (tmp_cmd strjoin)");
	*cmd = find_check_cmd(path, tmp_cmd);
	if (!(*cmd))
		ps_error("Error: no access cmd");
	free(tmp_cmd);
	ft_free(path);
	return (cmd);
}

void	parse(t_pipex *req, char **envr)
{
	req->inp = open(req->argv[1], O_RDONLY);
	if (req->inp < 0)
		ps_error("Error: cannot open file1");
	req->out = open(req->argv[4], O_WRONLY);
	if (req->out < 0)
		ps_error("Error: cannot open/create file2");
	req->cmd1 = find_cmd(req->argv[2], envr);
	req->cmd2 = find_cmd(req->argv[3], envr);
}