/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:33:49 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:33:51 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *sc, size_t n)
{
	if (!dest && !sc)
		return (dest);
	while (n--)
	{
		((char *)dest)[n] = ((char *)sc)[n];
	}
	return (dest);
}
