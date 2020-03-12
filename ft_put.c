/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:24:00 by htillman          #+#    #+#             */
/*   Updated: 2019/03/05 21:26:26 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_str(t_img *img)
{
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 30, 16777215,
		"Enter: change color");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 45, 16777215,
		"S: start colors");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 60, 16777215,
		"+: increase iterations");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 75, 16777215,
		"-: decrease iterations");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 90, 16777215,
		"arrows: move");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 105, 16777215,
		"mouse: move and zoom");
}

void			ft_put(t_img *img, t_fractol *f)
{
	int	k;

	k = 20;
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 10, 16777215, img->titel);
	ft_str(img);
	if (f->type == 'J')
		mlx_string_put(img->mlx_ptr, img->win_ptr, 10, 120, 16777215,
			"space: freeze");
	ft_key(img, f);
}
