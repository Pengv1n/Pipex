/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:34:11 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:34:13 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *sc, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !sc)
		return (dest);
	if (dest < sc)
	{
		d = (char *)dest;
		s = (char *)sc;
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = (char *)dest + n;
		s = (char *)sc + n;
		while (n--)
		{
			*--d = *--s;
		}
	}
	return (dest);
}
