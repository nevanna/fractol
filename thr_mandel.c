/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:10:21 by htillman          #+#    #+#             */
/*   Updated: 2019/03/05 22:57:29 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_inn(t_x *l, t_fractol *dat)
{
	l->y = dat->yw_start - 1;
	l->x = 0;
	l->color = 0;
}

static void	ft_num(t_fractol *dat, t_x l, int *i)
{
	dat->set.c_re = 1.5 * (l.x + dat->img.movex - dat->xwin / 2) /
		(0.5 * dat->img.zoom * dat->xwin);
	dat->set.c_im = (l.y + dat->img.movey - dat->ywin / 2) /
		(0.5 * dat->img.zoom * dat->ywin);
	dat->set.old_re = 0;
	dat->set.old_im = 0;
	dat->set.new_re = 0;
	dat->set.new_im = 0;
	(*i) = 1;
}

static void	ft_sm(t_fractol *dat)
{
	dat->set.old_re = dat->set.new_re;
	dat->set.old_im = dat->set.new_im;
	dat->set.new_re = dat->set.old_re * dat->set.old_re -
		dat->set.old_im * dat->set.old_im + dat->set.c_re;
	dat->set.new_im = 2 * dat->set.old_re * dat->set.old_im
		+ dat->set.c_im;
}

static void	ft_if_m(t_fractol *dat, t_x *l, int i)
{
	l->color = dat->set.color + dat->m_col * i;
	if (i == dat->set.max_iter)
		l->color = 0xff7518;
}

void		*ft_mal(void *data)
{
	t_fractol	*dat;
	t_x			l;
	int			i;

	dat = (t_fractol *)data;
	ft_inn(&l, dat);
	while (++l.y < dat->yw_end)
	{
		l.x = 0;
		while (l.x < dat->xwin)
		{
			ft_num(dat, l, &i);
			while (i < dat->set.max_iter)
			{
				ft_sm(dat);
				if ((dat->set.new_re * dat->set.new_re +
					dat->set.new_im * dat->set.new_im) > 4)
					break ;
				i++;
			}
			ft_if_m(dat, &l, i);
			image_set_pixel(&(dat->img), l.x++, l.y, l.color);
		}
	}
	return (NULL);
}
