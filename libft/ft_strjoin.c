/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:37:08 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:37:11 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	unsigned int	i;
	char			*res;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!res)
		return (NULL);
	i--;
	while (s1[++i])
		res[i] = s1[i];
	i--;
	while (s2[++i - l1])
		res[i] = s2[i - l1];
	res[i] = '\0';
	return (res);
}
