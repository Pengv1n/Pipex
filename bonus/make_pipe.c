#include "pipex.h"

void	close_files(t_pipex *req)
{
	int i;

	i = -1;
	while (++i < (req->n_cmd - 1 + req->l) * 2)
		close(req->fd[i]);
	if (!(req->l))
		close(req->inp);
	close(req->out);
}

void	child(char **cmd, int in, int out, t_pipex *req)
{
	dup2(in, 0);
	dup2(out, 1);
	close_files(req);
	execve(cmd[0], cmd, NULL);
	error("Error: execve");
}

void	child_limiter(int in, int out, t_pipex *req)
{
	char	*line;
	int r;

	while (1)
	{
		line = get_next_line(in);
		if (!line)
			break;
		if (ft_strnstr(req->limiter, line, ft_strlen(req->limiter)))
			break;
		ft_putstr_fd(line, out);
		free(line);
	}
	close_files(req);
	exit(0);
}

void	make_child(t_pipex *req)
{
	int i;

	i = -1;
	while (++i < req->n_cmd + req->l)
	{
		req->pid[i] = fork();
		if (req->pid[i] == -1)
			error("Error: fork");
		if (req->pid[i] == 0)
		{
			if (i == 0 && req->l)
				child_limiter(req->inp, req->out, req);
			else if (i == 0)
				child(req->cmd[i], req->inp, req->fd[1], req);
			else if (i == req->n_cmd - 1 + req->l)
				child(req->cmd[i], req->fd[2 * (i - 1)], req->out, req);
			else
				child(req->cmd[i], req->fd[2 * i - 1)], req->fd[i * 2], req);
		}
	}
}

void	make_pipe(t_pipex *req)
{
	int i;
	int	status;

	i = -1;
	while (++i < req->n_cmd - 1 + req->l)
		if (pipe(req->fd + i * 2) == -1)
			error("Error: pipe");
	make_child(req);
	close_files(req);
	i = -1;
	status = 0;
	while (++i < (req->n_cmd + req->l))
	{
		waitpid(req->pid[i], &req->status[i], 0);
		if (WEXITSTATUS(req->status[i]) != 0)
			status = 1;
	}
	if (status)
		error("Error: status");
}