/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:26:17 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/10 01:26:24 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_neg(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	check_res(int ret, int neg, int x)
{
	if (x >= 19)
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	return (ret * neg);
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	neg;
	int	x;

	x = -1;
	neg = 1;
	ret = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (nptr[x + 1] == '-' || nptr[x + 1] == '+')
	{
		neg = check_neg(nptr[x + 1]);
		x++;
	}
	while (nptr[++x])
	{
		if (ft_isdigit(nptr[x]))
			ret = (ret * 10) + (nptr[x] - '0');
		else
			return (check_res(ret, neg, x));
	}
	return (check_res(ret, neg, x));
}
