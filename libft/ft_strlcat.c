/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:37:26 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:37:29 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *sc, size_t size)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_sc;

	i = 0;
	size_sc = 0;
	i = ft_strlen(dest);
	size_sc = ft_strlen(sc);
	size_dest = i;
	while (*sc && i + 1 < size)
		dest[i++] = *(sc++);
	dest[i] = '\0';
	if (size_dest > size)
		i = size;
	else
		i = size_dest;
	return (size_sc + i);
}
