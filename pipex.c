
#include "pipex.h"

void	ps_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}

static void	child1(t_pipex *req)
{
	dup2(req->inp, 0);
	dup2(req->fd[1], 1);
	close (req->fd[0]);
	close (req->fd[1]);
	close (req->inp);
	close (req->out);
	execve(req->cmd1[0], req->cmd1, NULL);
	ps_error("Error: execve mistake");
}

static void	child2(t_pipex *req)
{
	dup2(req->fd[0], 0);
	dup2(req->out, 1);
	close (req->fd[0]);
	close (req->fd[1]);
	close (req->inp);
	close (req->out);
	execve(req->cmd2[0], req->cmd2, NULL);
	ps_error("Error: execve mistake");
}

static void	make_cmd(t_pipex *req)
{
	int	pid[2];
	int	status[2];

	pid[0] = fork();
	if (pid[0] == -1)
		ps_error("Error: fork mistake");
	if (pid[0] == 0)
		child1(req);
	pid[1] = fork();
	if (pid[1] == -1)
		ps_error("Error: fork mistake");
	if (pid[1] == 0)
		child2(req);
	close (req->fd[0]);
	close (req->fd[1]);
	close (req->inp);
	close (req->out);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	if (WEXITSTATUS(status[0]) == 0 && WEXITSTATUS(status[1]) == 0)
		return ;
	ps_error("Error: execve comand flag error");
}

int main(int argc, char **argv, char **envr)
{
	t_pipex *req;

	if (argc != 5)
		ps_error("ERROR");
	req = (t_pipex *) malloc(sizeof(t_pipex));
	if (!req)
		ps_error("ERROR");
	req->argv =argv;
	parse(req, envr);
	if (pipe(req->fd) == -1)
		ps_error("ERROR");
	make_cmd(req);
	ft_free(req->cmd1);
	ft_free(req->cmd2);
	ft_free(req->argv);
	free(req);
	return (0);
}