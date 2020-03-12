/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_k.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:41:20 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 16:24:29 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_what(t_fractol *f)
{
	if (f->type == 'J')
		thr_julia(f);
	else if (f->type == 'M')
		thr_mandel(f);
	else if (f->type == 'S')
		thr_spider(f);
	else if (f->type == 'B')
		thr_br_sh(f);
	else if (f->type == 'D')
		thr_drop(f);
	else if (f->type == 'L')
		thr_lambda(f);
}

int			ft_zoom_point(int but, int x, int y, t_fractol *f)
{
	if (but == 4)
	{
		f->img.movex += (x - f->img.width / 2 + f->img.movex) * (1.1f - 1.0f);
		f->img.movey += (y - f->img.height / 2 + f->img.movey) * (1.1f - 1.0f);
		f->img.zoom *= 1.1f;
	}
	if (but == 5)
	{
		f->img.movex -= (x - f->img.width / 2 + f->img.movex) * (1.1f - 1.0f);
		f->img.movey -= (y - f->img.height / 2 + f->img.movey) * (1.1f - 1.0f);
		f->img.zoom *= 0.9f;
	}
	if (but == 1)
		f->mv_flag++;
	ft_what(f);
	return (1);
}

static void	ft_eq(int x, int y, t_fractol *f)
{
	f->xpr = x;
	f->ypr = y;
}

int			ft_change_c(int x, int y, t_fractol *f)
{
	if (f->sp_flag == 0)
	{
		if (f->xpr == 0 && f->ypr == 0)
			ft_eq(x, y, f);
		if (f->type == 'J')
		{
			f->set.c_re += (f->xpr - x) / 500.f;
			f->set.c_im += (f->ypr - y) / 500.f;
			thr_julia(f);
		}
	}
	if (f->mv_flag != 0)
	{
		if (f->xpr == 0 && f->ypr == 0)
			ft_eq(x, y, f);
		f->img.movex = (f->img.movex - x + f->xpr);
		f->img.movey = (f->img.movey - y + f->ypr);
		ft_what(f);
	}
	ft_eq(x, y, f);
	return (0);
}

void		image_set_pixel(t_img *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	*(int *)(image->adr + (x * image->bitspp + y * image->size_line)) = color;
}
