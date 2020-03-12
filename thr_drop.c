/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr_drop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:40:16 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 16:11:03 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_innnn(t_x *l, t_fractol *dat)
{
	l->y = dat->yw_start;
	l->x = 0;
}

static void	ft_nummm(t_fractol *dat, t_x l, int *i)
{
	dat->set.c_re = 1.5 * (l.x + dat->img.movex - dat->xwin / 2) /
		(0.5 * dat->img.zoom * dat->xwin);
	dat->set.c_im = (l.y + dat->img.movey - dat->ywin / 2) /
		(0.5 * dat->img.zoom * dat->ywin);
	dat->set.new_re = dat->set.c_re;
	dat->set.new_im = dat->set.c_im;
	(*i) = 1;
}

static void	ft_sp_l(t_fractol *dat)
{
	dat->set.old_re = dat->set.new_re;
	dat->set.old_im = dat->set.new_im;
	dat->set.new_re = tan(dat->set.old_re * dat->set.old_re
		- dat->set.old_im * dat->set.old_im + dat->set.c_re);
	dat->set.new_im = 2 * (tan(dat->set.old_im * dat->set.old_re))
		+ dat->set.c_im;
}

static int	ft_if_l(t_fractol *dat, int i)
{
	int s1;
	int s2;
	int s3;

	s1 = dat->scheme / 100;
	s2 = (dat->scheme / 10) % 10;
	s3 = dat->scheme % 10;
	if (i <= dat->set.max_iter / 2)
		return ((255 / (dat->set.max_iter / 2 - i + 1)) << (s1 * 8));
	else
		return (255 << (s1 * 8) | (int)(255 * (i - dat->set.max_iter / 2 + 1) /
		(dat->set.max_iter / 2)) << (s2 * 8) |
		(int)(255 * ((i - dat->set.max_iter / 2 + 1) /
			(dat->set.max_iter / 2))) << (s3 * 8));
			return (0);
}

void		*ft_drop(void *data)
{
	t_fractol	*dat;
	t_x			l;
	int			i;

	dat = (t_fractol *)data;
	ft_innnn(&l, dat);
	while (l.y < dat->yw_end)
	{
		l.x = 0;
		while (l.x < dat->xwin)
		{
			ft_nummm(dat, l, &i);
			while (i < dat->set.max_iter)
			{
				ft_sp_l(dat);
				if ((dat->set.new_re * dat->set.new_re +
					dat->set.new_im * dat->set.new_im) > 4)
					break ;
				i++;
			}
			image_set_pixel(&(dat->img), l.x++, l.y, ft_if_l(dat, i));
		}
		l.y++;
	}
	return (NULL);
}
