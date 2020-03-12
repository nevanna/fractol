/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:58:50 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 17:15:16 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_exit_x(t_img *img)
{
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	exit(1);
	return (0);
}

int				ft_frozen(t_fractol *f)
{
	f->sp_flag++;
	if (f->sp_flag % 2 == 0)
		f->sp_flag = 0;
	if (f->type == 'L')
	{
		f->lam = f->lam - 0.01;
		ft_what(f);
	}
	return (1);
}

static int		ft_ch_key(int key, t_fractol *f)
{
	if (key == 53)
		ft_exit_x(&(f->img));
	if (key == 78)
		ft_iter_down(f);
	if (key == 69)
		ft_iter_up(f);
	if (key == 49)
		ft_frozen(f);
	if (key == 125)
		ft_up(f);
	if (key == 126)
		ft_down(f);
	if (key == 123)
		ft_left(f);
	if (key == 124)
		ft_right(f);
	if (key == 36)
		ft_color(f);
	if (key == 1)
		ft_start(f);
	return (0);
}

int				ft_mv_flag(int but, int x, int y, t_fractol *f)
{
	x = 0;
	y = 0;
	if (but == 1)
		f->mv_flag = 0;
	return (1);
}

void			ft_key(t_img *img, t_fractol *f)
{
	mlx_key_hook(img->win_ptr, ft_ch_key, f);
	mlx_hook(img->win_ptr, 17, 0, ft_exit_x, img);
	mlx_hook(img->win_ptr, 6, 0, ft_change_c, f);
	mlx_hook(img->win_ptr, 4, 0, ft_zoom_point, f);
	mlx_hook(img->win_ptr, 5, 0, ft_mv_flag, f);
}
