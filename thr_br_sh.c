/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr_br_sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:28:51 by htillman          #+#    #+#             */
/*   Updated: 2019/03/05 22:55:14 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_is(t_x *l, t_fractol *dat)
{
	l->y = dat->yw_start - 1;
	l->x = 0;
	l->color = 0;
}

static void	ft_nums(t_fractol *dat, t_x l, int *i)
{
	dat->set.c_re = 1.5 * (l.x + dat->img.movex - dat->xwin / 2) /
		(0.5 * dat->img.zoom * dat->xwin);
	dat->set.c_im = (l.y + dat->img.movey - dat->ywin / 2) /
		(0.5 * dat->img.zoom * dat->ywin);
	dat->set.new_re = dat->set.c_re;
	dat->set.new_im = dat->set.c_im;
	(*i) = 1;
}

static void	ft_sms(t_fractol *dat)
{
	dat->set.old_re = dat->set.new_re;
	dat->set.old_im = dat->set.new_im;
	dat->set.new_re = fabs(dat->set.old_re * dat->set.old_re
		- dat->set.old_im * dat->set.old_im + dat->set.c_re);
	dat->set.new_im = 2 * (fabs(dat->set.old_im * dat->set.old_re))
		+ dat->set.c_im;
}

static void	ft_if_ms(t_fractol *dat, t_x *l, int i)
{
	if (i % 5 == 0)
		l->color = dat->set.color + dat->b_col_f * i;
	else if (i % 3 == 0)
		l->color = dat->set.color + dat->b_col_s * i;
	else
		l->color = dat->set.color + dat->b_col_t * i;
	if (i == dat->set.max_iter)
		l->color = 0xffffff;
}

void		*ft_b_s(void *data)
{
	t_fractol	*dat;
	t_x			l;
	int			i;

	dat = (t_fractol *)data;
	ft_is(&l, dat);
	while (++l.y < dat->yw_end)
	{
		l.x = 0;
		while (l.x < dat->xwin)
		{
			ft_nums(dat, l, &i);
			while (i < dat->set.max_iter)
			{
				ft_sms(dat);
				if ((dat->set.new_re * dat->set.new_re +
					dat->set.new_im * dat->set.new_im) > 4)
					break ;
				i++;
			}
			ft_if_ms(dat, &l, i);
			image_set_pixel(&(dat->img), l.x++, l.y, l.color);
		}
	}
	return (NULL);
}
