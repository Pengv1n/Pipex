/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:39:16 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:39:21 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (!is_in_set(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
	{
		ret = ft_strdup("");
		if (!ret)
			return (NULL);
		else
			return (ret);
	}
	while (!is_in_set(s1[end - 1], set))
		end--;
	ret = ft_substr(s1, start, end - start);
	return (ret);
}
