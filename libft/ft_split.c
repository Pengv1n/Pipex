/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:35:48 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:36:09 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clear(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	ft_strlen_c(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && str[i + 1] && str[i + 1] == c)
			count++;
		if (str[i] != c && !str[i + 1])
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			start;
	char			**ret;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	ret = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (s[i++] == c)
		start++;
	i = -1;
	while (++i < ft_count_words(s, c))
	{
		ret[i] = ft_substr(s, start, ft_strlen_c(&s[start], c));
		if (!ret[i])
			return (ft_clear(ret));
		start += ft_strlen_c(&s[start], c);
		while (s[start] == c)
			start++;
	}
	ret[i] = NULL;
	return (ret);
}
