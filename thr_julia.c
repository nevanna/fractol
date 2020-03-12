/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:26:41 by htillman          #+#    #+#             */
/*   Updated: 2019/03/05 22:54:55 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_i(t_x *l, t_fractol *dat)
{
	l->y = dat->yw_start - 1;
	l->x = 0;
	l->color = 0;
}

static void		ft_sp(t_fractol *dat)
{
	dat->set.old_re = dat->set.new_re;
	dat->set.old_im = dat->set.new_im;
	dat->set.new_re = dat->set.old_re * dat->set.old_re -
		dat->set.old_im * dat->set.old_im + dat->set.c_re;
	dat->set.new_im = 2 * dat->set.old_re * dat->set.old_im + dat->set.c_im;
}

static void		ft_spp(t_fractol *dat, int *i, t_x l)
{
	dat->set.new_re = 1.5 * (l.x + dat->img.movex - dat->xwin / 2) /
		(0.5 * dat->img.zoom * dat->xwin);
	dat->set.new_im = (l.y + dat->img.movey - dat->ywin / 2) /
		(0.5 * dat->img.zoom * dat->ywin);
	(*i) = 1;
}

static void		ft_if(t_fractol *dat, t_x *l, int i)
{
	if (i % 2 == 0)
		l->color = dat->set.color + dat->j_col_s * (i);
	else
		l->color = dat->set.color + dat->j_col_f * (i);
	if (i == dat->set.max_iter)
		l->color = 0xffffff;
}

void			*ft_ju(void *data)
{
	t_fractol	*dat;
	t_x			l;
	int			i;

	dat = (t_fractol *)data;
	ft_i(&l, dat);
	while (++l.y < dat->yw_end)
	{
		l.x = 0;
		while (l.x < dat->xwin)
		{
			ft_spp(dat, &i, l);
			while (i < dat->set.max_iter)
			{
				ft_sp(dat);
				if ((dat->set.new_re * dat->set.new_re +
					dat->set.new_im * dat->set.new_im) > 4)
					break ;
				i++;
			}
			ft_if(dat, &l, i);
			image_set_pixel(&(dat->img), l.x++, l.y, l.color);
		}
	}
	return (NULL);
}
