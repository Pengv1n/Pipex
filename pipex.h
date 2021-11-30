#ifndef PIPEX_H
# define PIPEX_H

# include "stdlib.h"
#include "fcntl.h"
#include "libft/libft.h"
#include "unistd.h"
#include "sys/wait.h"

typedef struct s_pipex
{
	char	**argv;
	int	fd[2];
	int inp;
	int	out;
	char	**cmd1;
	char	**cmd2;
} t_pipex;

void parse(t_pipex *req, char **envr);
void	error(char *str);
void	ft_free(char **s);

#endif