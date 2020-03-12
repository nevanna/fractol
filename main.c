/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:23:13 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 20:06:55 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_argc(int argc, char **argv, t_fractol *f)
{
	if (argc == 1)
		ft_mega_return();
	else if (argc == 2 || argc == 3)
	{
		if (ft_strlen(argv[1]) == 1)
			ft_is_that(argv[1][0], f);
		else
			ft_mega_return();
		if (argc == 3 && ft_strlen(argv[2]) == 1)
		{
			if (argv[2][0] != 'M' && argv[2][0] != 'J'
				&& argv[2][0] != 'S' && argv[2][0] != 'B'
				&& argv[2][0] != 'D' && argv[2][0] != 'L')
				ft_mega_return();
		}
	}
	else
		ft_mega_return();
}

void		ft_img(t_img *img)
{
	if (!(img->img_ptr = mlx_new_image(img->mlx_ptr, 2000, 1200)))
		ft_return("error:img_ptr");
	img->adr = mlx_get_data_addr(img->img_ptr, &img->bitspp,
		&img->size_line, &img->endian);
	img->bitspp /= 8;
}

void		ft_titel(t_fractol *f)
{
	if (f->type == 'M')
		f->img.titel = "Mandelbrot";
	else if (f->type == 'J')
		f->img.titel = "Julia";
	else if (f->type == 'S')
		f->img.titel = "Spider";
	else if (f->type == 'B')
		f->img.titel = "Burning ship";
	else if (f->type == 'D')
		f->img.titel = "Drop";
	else if (f->type == 'L')
		f->img.titel = "Lambda";
	ft_img(&(f->img));
}

void		ft_init(t_fractol *f)
{
	f->xwin = 2000;
	f->ywin = 1200;
	f->xpr = 0;
	f->ypr = 0;
	f->img.height = f->ywin;
	f->img.width = f->xwin;
	f->img.mlx_ptr = mlx_init();
	f->img.size_line = 0;
	if ((f->img.win_ptr = mlx_new_window(f->img.mlx_ptr, f->xwin,
		f->ywin, "Fractol")) == NULL)
		ft_return("error: mlx->win");
	f->img.zoom = 1;
	f->img.movex = 0;
	f->img.movey = 0;
	f->set.max_iter = 24;
	f->set.color = 0;
	f->set.c_re = -0.7;
	f->set.c_im = 0.27015;
	f->t = 120;
	f->sp_flag = 0;
	ft_initt(f);
	ft_titel(f);
}

int			main(int argc, char **argv)
{
	pid_t		pid;
	t_fractol	f;
	char		**argv_list;

	ft_argc(argc, argv, &f);
	if (argc == 3)
	{
		pid = fork();
		if (pid == -1)
			ft_return("can't fork, error occured");
		else if (pid == 0)
		{
			ft_get_new_ar_l(&argv_list, argv[0], argv[2]);
			execvp("./fractol", argv_list);
			exit(0);
		}
		else
		{
			ft_call(argc, argv, &f);
			exit(0);
		}
	}
	ft_call(argc, argv, &f);
	return (0);
}
