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
	cmd[0] = find_check_cmd(path, tmp_cmd);
	if (!(cmd[0]))
		error("Error: no access cmd");
	free(tmp_cmd);
	ft_free(path);
	return (cmd);
}

void	choose_input(t_pipex *req, int argc)
{
	if (ft_strnstr(req->argv[1], "here_doc", ft_strlen("here_doc")))
	{
		req->limiter = req->argv[2];
		req->l = 1;
		req->inp = 0;
		req->out = open(req->argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0777);
		if (req->out == -1)
			error("Error: can't open file out");
		req->n_cmd = argc - 1 - 3;
	}
	else
	{
		req->l = 0;
		req->limiter = NULL;
		if (access(req->argv[1], F_OK) == -1)
			error("Error: file inp not exists");
		req->inp = open(req->argv[1], O_RDONLY);
		if (req->inp == -1)
			error("Error: can't open file inp");
		req->out = open(req->argv[argc - 1], \
			O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (req->out == -1)
			error("Error: can't open file out");
		req->n_cmd = argc - 1 - 2;
	}
}

void	parse(t_pipex *req, char **envr, int argc)
{
	int i;

	choose_input(req, argc);
	req->cmd = (char ***)malloc(sizeof(char **) * (req->n_cmd + 1 + req->l));
	if (!(req->cmd))
		error("Error: malloc req->cmd");
	req->cmd[req->n_cmd + req->l] = NULL;
	if (req->l)
		req->cmd[0] = NULL;
	i = -1;
	while (++i < req->n_cmd)
		req->cmd[i + req->l] = find_cmd( \
		req->argv[argc - 1 - req->n_cmd + i], envr);
}
