/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:49:24 by htillman          #+#    #+#             */
/*   Updated: 2019/03/05 18:54:30 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_iter_down(t_fractol *f)
{
	f->set.max_iter = f->set.max_iter - 2;
	ft_what(f);
	return (0);
}

int	ft_iter_up(t_fractol *f)
{
	f->set.max_iter = f->set.max_iter + 2;
	ft_what(f);
	return (0);
}

int	ft_up(t_fractol *f)
{
	f->img.movey = f->img.movey + 10;
	ft_what(f);
	return (1);
}

int	ft_down(t_fractol *f)
{
	f->img.movey = f->img.movey - 10;
	ft_what(f);
	return (1);
}

int	ft_left(t_fractol *f)
{
	f->img.movex = f->img.movex - 10;
	ft_what(f);
	return (1);
}
