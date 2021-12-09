/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:27:59 by aregenia          #+#    #+#             */
/*   Updated: 2021/11/30 17:28:01 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		free (s[i]);
	free(s);
}

char	**find_path(char **envr)
{
	char	**path;
	int		i;

	path = ((void *)0);
	i = -1;
	while (envr[++i])
	{
		if (ft_strnstr(envr[i], "PATH=/home", ft_strlen(envr[i])))
		{
			path = ft_split(envr[i] + ft_strlen("PATH="), ':');
			break ;
		}
	}
	if (!envr[i])
		error("Error: no path in envr");
	if (!path)
		error("Error: ft_split path");
	return (path);
}

char	*find_check_cmd(char **path, char *tmp_cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], tmp_cmd);
		if (!tmp)
			error("Error: strjoin tmp");
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
		error("Error: split cmd");
	tmp_cmd = ft_strjoin("/", cmd[0]);
	if (!tmp_cmd)
		error("Error: strjoin tmp_cmd");
	free (cmd[0]);
	cmd[0] = find_check_cmd(path, tmp_cmd);
	if (!(cmd[0]))
		error("Error: no access cmd");
	free(tmp_cmd);
	ft_free(path);
	return (cmd);
}

void	parse(t_pipex *req, char **envr)
{
	req->inp = open(req->argv[1], O_RDONLY);
	if (req->inp == -1)
		error("Error: cannot open file inp");
	req->out = open(req->argv[4], O_WRONLY);
	if (req->out == -1)
		error("Error: cannot open file out");
	req->cmd1 = find_cmd(req->argv[2], envr);
	req->cmd2 = find_cmd(req->argv[3], envr);
}
