/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:39:33 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/14 17:55:57 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	k;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	i = start;
	while (s[i] && i <= start + len - 1)
		i++;
	res = (char *)malloc(sizeof(char) * (i - start + 1));
	if (!res)
		return (NULL);
	k = 0;
	while (start < i)
		res[k++] = s[start++];
	res[k] = '\0';
	return (res);
}
