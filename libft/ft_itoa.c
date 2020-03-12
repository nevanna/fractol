/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:55:31 by htillman          #+#    #+#             */
/*   Updated: 2019/02/18 21:29:19 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_minus(int r, int n)
{
	char	*new;

	new = ft_strnew(r + 1);
	if (!new)
		return (NULL);
	new[0] = '-';
	r++;
	while (r >= 2)
	{
		new[r - 1] = n % 10 + '0';
		n = n / 10;
		r--;
	}
	return (new);
}

static	char	*ft_plus(int r, int n)
{
	char *new;

	new = ft_strnew(r);
	if (!new)
		return (NULL);
	while (r >= 0)
	{
		new[r - 1] = n % 10 + '0';
		n = n / 10;
		r--;
	}
	return (new);
}

char			*ft_itoa(int n)
{
	char	sign;
	int		r;
	int		tmp;

	tmp = n;
	r = 0;
	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = '-';
		tmp = tmp * (-1);
	}
	while (tmp)
	{
		tmp = tmp / 10;
		r++;
	}
	if (sign == '-')
		return (ft_minus(r, n * (-1)));
	return (ft_plus(r, n));
}
