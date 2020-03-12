/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr_spider.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:34:07 by htillman          #+#    #+#             */
/*   Updated: 2019/03/05 22:55:54 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_innn(t_x *l, t_fractol *dat)
{
	l->y = dat->yw_start - 1;
	l->x = 0;
}

static void	ft_numm(t_fractol *dat, t_x l, int *i)
{
	dat->set.new_re = 1.5 * (l.x + dat->img.movex - dat->xwin / 2) /
		(0.5 * dat->img.zoom * dat->xwin);
	dat->set.new_im = (l.y + dat->img.movey - dat->ywin / 2) /
		(0.5 * dat->img.zoom * dat->ywin);
	dat->set.c_re = dat->set.new_re;
	dat->set.c_im = dat->set.new_im;
	(*i) = 1;
}

static void	ft_sp_s(t_fractol *dat)
{
	dat->set.old_re = dat->set.new_re;
	dat->set.old_im = dat->set.new_im;
	dat->set.pi = dat->set.c_im;
	dat->set.pr = dat->set.c_re;
	dat->set.new_re = dat->set.old_re * dat->set.old_re -
		dat->set.old_im * dat->set.old_im + dat->set.pr;
	dat->set.new_im = 2 * dat->set.old_re * dat->set.old_im + dat->set.pi;
	dat->set.c_re = dat->set.pr / 2 + dat->set.new_re;
	dat->set.c_im = dat->set.pi / 2 + dat->set.new_im;
}

static void	ft_if_s(t_fractol *dat, t_x *l, int i)
{
	l->color = dat->set.color + dat->s_col * i;
	if (i == dat->set.max_iter)
		l->color = 0xffffff;
}

void		*ft_spi(void *data)
{
	t_fractol	*dat;
	t_x			l;
	int			i;

	dat = (t_fractol *)data;
	ft_innn(&l, dat);
	while (++l.y < dat->yw_end)
	{
		l.x = 0;
		while (l.x < dat->xwin)
		{
			ft_numm(dat, l, &i);
			while (i < dat->set.max_iter)
			{
				ft_sp_s(dat);
				if ((dat->set.new_re * dat->set.new_re + dat->set.new_im
					* dat->set.new_im) > 4)
					break ;
				i++;
			}
			ft_if_s(dat, &l, i);
			image_set_pixel(&(dat->img), l.x++, l.y, l.color);
		}
	}
	return (NULL);
}
