/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:32:41 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:32:59 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbr_plus(int n, char *str)
{
	long	num;
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = -1;
	num = n;
	if (n < 0)
		num *= -1;
	while (num > 9)
	{
		str[i++] = (num % 10) + '0';
		num = num / 10;
	}
	str[i++] = num + '0';
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	while (++j < i / 2)
	{
		tmp = str[j];
		str[j] = str[i - 1 - j];
		str[i - 1 - j] = tmp;
	}
}

static int	ft_size_str(long num)
{
	int	size;

	size = 0;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	while (num > 9)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_size_str(n) + 1));
	if (!str)
		return (NULL);
	ft_nbr_plus(n, str);
	return (str);
}
