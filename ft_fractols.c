/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:32:42 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 16:11:57 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thr_mandel(t_fractol *f)
{
	int			step;
	int			t;
	pthread_t	*threads;
	t_fractol	*thr_data;

	t = 0;
	if (!(threads = (pthread_t *)malloc((f->t) * sizeof(pthread_t))))
		ft_return("error: malloc");
	if (!(thr_data = (t_fractol *)malloc((f->t) * sizeof(t_fractol))))
		ft_return("error: malloc");
	step = f->ywin / f->t;
	while (t < f->t)
	{
		ft_memcpy(&(thr_data[t]), f, sizeof(t_fractol));
		thr_data[t].yw_start = step * (t);
		thr_data[t].yw_end = step * (t + 1);
		pthread_create(&threads[t], NULL, ft_mal, &(thr_data[t]));
		t++;
	}
	t = 0;
	while (t < f->t)
		pthread_join(threads[t++], NULL);
	free(threads);
	free(thr_data);
	ft_put(&(f->img), f);
}

void	thr_julia(t_fractol *f)
{
	int			step;
	int			t;
	pthread_t	*threads;
	t_fractol	*thr_data;

	t = 0;
	if (!(threads = (pthread_t *)malloc((f->t) * sizeof(pthread_t))))
		ft_return("error: malloc");
	if (!(thr_data = (t_fractol *)malloc((f->t) * sizeof(t_fractol))))
		ft_return("error: malloc");
	step = f->ywin / f->t;
	while (t < f->t)
	{
		ft_memcpy(&(thr_data[t]), f, sizeof(t_fractol));
		thr_data[t].yw_start = step * (t);
		thr_data[t].yw_end = step * (t + 1);
		pthread_create(&threads[t], NULL, ft_ju, &(thr_data[t]));
		t++;
	}
	t = 0;
	while (t < f->t)
		pthread_join(threads[t++], NULL);
	free(threads);
	free(thr_data);
	ft_put(&(f->img), f);
}

void	thr_spider(t_fractol *f)
{
	int			step;
	int			t;
	pthread_t	*threads;
	t_fractol	*thr_data;

	t = 0;
	if (!(threads = (pthread_t *)malloc((f->t) * sizeof(pthread_t))))
		ft_return("error: malloc");
	if (!(thr_data = (t_fractol *)malloc((f->t) * sizeof(t_fractol))))
		ft_return("error: malloc");
	step = f->ywin / f->t;
	while (t < f->t)
	{
		ft_memcpy(&(thr_data[t]), f, sizeof(t_fractol));
		thr_data[t].yw_start = step * (t);
		thr_data[t].yw_end = step * (t + 1);
		pthread_create(&threads[t], NULL, ft_spi, &(thr_data[t]));
		t++;
	}
	t = 0;
	while (t < f->t)
		pthread_join(threads[t++], NULL);
	free(threads);
	free(thr_data);
	ft_put(&(f->img), f);
}

void	thr_br_sh(t_fractol *f)
{
	int			step;
	int			t;
	pthread_t	*threads;
	t_fractol	*thr_data;

	t = 0;
	if (!(threads = (pthread_t *)malloc((f->t) * sizeof(pthread_t))))
		ft_return("error: malloc");
	if (!(thr_data = (t_fractol *)malloc((f->t) * sizeof(t_fractol))))
		ft_return("error: malloc");
	step = f->ywin / f->t;
	while (t < f->t)
	{
		ft_memcpy(&(thr_data[t]), f, sizeof(t_fractol));
		thr_data[t].yw_start = step * (t);
		thr_data[t].yw_end = step * (t + 1);
		pthread_create(&threads[t], NULL, ft_b_s, &(thr_data[t]));
		t++;
	}
	t = 0;
	while (t < f->t)
		pthread_join(threads[t++], NULL);
	free(threads);
	free(thr_data);
	ft_put(&(f->img), f);
}

void	thr_drop(t_fractol *f)
{
	int			step;
	int			t;
	pthread_t	*threads;
	t_fractol	*thr_data;

	t = 0;
	if (!(threads = (pthread_t *)malloc((f->t) * sizeof(pthread_t))))
		ft_return("error: malloc");
	if (!(thr_data = (t_fractol *)malloc((f->t) * sizeof(t_fractol))))
		ft_return("error: malloc");
	step = f->ywin / f->t;
	while (t < f->t)
	{
		ft_memcpy(&(thr_data[t]), f, sizeof(t_fractol));
		thr_data[t].yw_start = step * (t);
		thr_data[t].yw_end = step * (t + 1);
		pthread_create(&threads[t], NULL, ft_drop, &(thr_data[t]));
		t++;
	}
	t = 0;
	while (t < f->t)
		pthread_join(threads[t++], NULL);
	free(threads);
	free(thr_data);
	ft_put(&(f->img), f);
}
