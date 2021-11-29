/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:39:03 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:39:05 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
		if (str[i--] == (char)s)
			return ((char *)str + i + 1);
	return (NULL);
}
