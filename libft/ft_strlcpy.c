/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:37:42 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:37:44 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *sc, size_t dest_size)
{
	size_t	i;

	i = 0;
	if (!dest_size)
		return (ft_strlen(sc));
	while (sc[i] != '\0' && i < dest_size - 1)
	{
		dest[i] = sc[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(sc));
}
