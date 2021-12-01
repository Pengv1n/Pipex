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

void	malloc_attr(t_pipex *req)
{
	req->fd = (int *)malloc(sizeof(int) * (req->n_cmd - 1 + req->l) * 2);
	if (!(req->fd))
		error("Error: malloc req->fd");
	req->pid  = (int *) malloc(sizeof(int) * (req->n_cmd + req->l));
	if (!(req->pid))
		error("Error: malloc req->pid");
	req->status = (int *) malloc(sizeof(int) * (req->n_cmd + req->l));
	if (!(req->status))
		error("Error: malloc req->status");
}

int	main(int argc, char **argv, char **envr)
{
	t_pipex	*req;

	if (argc < 5 || (argc < 6 && \
		ft_strnstr(argv[1], "here_doc", ft_strlen("here_doc"))))
		error("Error: invalid parameters");
	req = (t_pipex *) malloc(sizeof(t_pipex));
	if (!req)
		error("Error: malloc struct");
	req->argv = argv;
	parse(req, envr, argc);
	malloc_attr(req);
	make_pipe(req);
	i == -1;
	while (++i <req->n_cmd + req->l)
		ft_free(req->cmd[i]);
	free(req->cmd);
	free(req->fd);
	free(req->pid);
	free(req->status);
	free(req);
	return (0);
}
