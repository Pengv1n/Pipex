/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:04:16 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/19 23:53:43 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	piece_or_null(char **text, char **line)
{
	*line = ft_strdup(*text);
	free(*text);
	*text = NULL;
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

char	*ret_line(char **text, char **buff)
{
	char	*piece_line;
	char	*line;
	int		i;

	free(*buff);
	*buff = NULL;
	i = 0;
	while ((*(*text + i) != '\n') && (*(*text + i) != '\0'))
		i++;
	if (*(*text + i) == '\n')
	{
		line = ft_substr(*text, 0, ++i);
		piece_line = ft_strdup(*text + i);
		free(*text);
		*text = piece_line;
	}
	else
	{
		piece_or_null(text, &line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*buff;
	char		*prev;
	ssize_t		n;

	n = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!text)
		text = ft_strdup("");
	while (!ft_strchr(text, '\n') && n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
			break ;
		buff[n] = '\0';
		prev = text;
		text = ft_strjoin(prev, buff);
		free(prev);
		prev = NULL;
	}
	return (ret_line(&text, &buff));
}
