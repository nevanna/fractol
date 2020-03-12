/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractols_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:12:25 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 16:13:35 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thr_lambda(t_fractol *f)
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
		pthread_create(&threads[t], NULL, ft_lam, &(thr_data[t]));
		t++;
	}
	t = 0;
	while (t < f->t)
		pthread_join(threads[t++], NULL);
	free(threads);
	free(thr_data);
	ft_put(&(f->img), f);
}
