/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:27:52 by aregenia          #+#    #+#             */
/*   Updated: 2021/11/30 17:27:54 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	child1(t_pipex *req)
{
	dup2(req->inp, 0);
	dup2(req->fd[1], 1);
	close (req->fd[0]);
	close (req->fd[1]);
	close (req->inp);
	close (req->out);
	execve(req->cmd1[0], req->cmd1, NULL);
	error("Error: execve1 mistake");
}

void	child2(t_pipex *req)
{
	dup2(req->fd[0], 0);
	dup2(req->out, 1);
	close (req->fd[0]);
	close (req->fd[1]);
	close (req->inp);
	close (req->out);
	execve(req->cmd2[0], req->cmd2, NULL);
	error("Error: execve2 mistake");
}

void	make_cmd(t_pipex *req)
{
	int	pid[2];
	int	status[2];

	pid[0] = fork();
	if (pid[0] == -1)
		error("Error: fork1 mistake");
	if (pid[0] == 0)
		child1(req);
	pid[1] = fork();
	if (pid[1] == -1)
		error("Error: fork2 mistake");
	if (pid[1] == 0)
		child2(req);
	close (req->fd[0]);
	close (req->fd[1]);
	close (req->inp);
	close (req->out);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	if (WIFEXITED(status[0]) != 0 && WIFEXITED(status[1]) != 0)
		return ;
	error("Error: execve command flag error");
}

int	main(int argc, char **argv, char **envr)
{
	t_pipex	*req;

	if (argc != 5)
		error("Error: invalid number variables");
	req = (t_pipex *) malloc(sizeof(t_pipex));
	if (!req)
		error("Error: malloc struct");
	req->argv = argv;
	parse(req, envr);
	if (pipe(req->fd) == -1)
		error("Error: pipe");
	make_cmd(req);
	ft_free(req->cmd1);
	ft_free(req->cmd2);
	free(req);
	return (0);
}
