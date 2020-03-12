/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kkk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:54:52 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 17:38:53 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_right(t_fractol *f)
{
	f->img.movex = f->img.movex + 10;
	ft_what(f);
	return (1);
}

void	ft_initt(t_fractol *f)
{
	f->s_col = 0xfa7db3;
	f->j_col_f = 655500;
	f->j_col_s = 255;
	f->m_col = 0xf2ad46;
	f->b_col_f = 0xff033e;
	f->b_col_s = 627478;
	f->b_col_t = 6555000;
	f->mv_flag = 0;
	f->scheme = 12;
	f->lam = 0.5;
	f->l_color = 0x7fffd4;
}

int		ft_start(t_fractol *f)
{
	f->s_col = 0xfa7db3;
	f->j_col_f = 655500;
	f->j_col_s = 255;
	f->m_col = 0xf2ad46;
	f->b_col_f = 0xff033e;
	f->b_col_s = 627478;
	f->b_col_t = 6555000;
	f->l_color = 0x7fffd4;
	f->scheme = 12;
	ft_what(f);
	return (1);
}

int		ft_color(t_fractol *f)
{
	f->s_col += 100;
	f->j_col_f += 100;
	f->j_col_s += 100;
	f->m_col += 100;
	f->b_col_f += 100;
	f->b_col_s += 100;
	f->b_col_t += 100;
	f->l_color += 100;
	f->scheme += 100;
	if (f->scheme > 210)
		f->scheme = 210;
	ft_what(f);
	return (1);
}

void	ft_call(int argc, char **argv, t_fractol *f)
{
	ft_argc(argc, argv, f);
	ft_init(f);
	ft_what(f);
	mlx_loop(f->img.mlx_ptr);
}
