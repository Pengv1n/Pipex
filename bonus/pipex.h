/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:27:41 by aregenia          #+#    #+#             */
/*   Updated: 2021/11/30 17:27:48 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "stdlib.h"
# include "fcntl.h"
# include "../libft/libft.h"
# include "unistd.h"
# include "sys/wait.h"

typedef struct s_pipex
{
	char	**argv;
	int		*fd;
	int		inp;
	int		out;
	char	*limiter;
	int		l;
	int 	n_cmd;
	char 	***cmd;
	int 	*status;
	int 	*pid;
}		t_pipex;

void	parse(t_pipex *req, char **envrm int argc);
void	error(char *str);
void	ft_free(char **s);

#endif