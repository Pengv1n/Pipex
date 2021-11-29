/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:38:47 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:38:48 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (!*little)
		return ((char *)big);
	b = 0;
	while (big[b])
	{
		l = 0;
		while (big[b + l] == little[l] && b + l < len)
			if (!little[++l])
				return ((char *)(big + b));
		b++;
	}
	return (0);
}
