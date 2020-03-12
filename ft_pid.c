/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:34:41 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 17:02:08 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_get_new_ar_l(char ***argv_list, char *a, char *c)
{
	if (!((*argv_list) = (char **)malloc(sizeof(char *) * 3)))
		ft_return("error: malloc0");
	(*argv_list)[0] = ft_strdup(a);
	(*argv_list)[1] = ft_strdup(c);
	(*argv_list)[2] = NULL;
	if (!((*argv_list)[0]) || !((*argv_list)[1]))
		ft_return("error: malloc2");
}

void	ft_is_that(char ar, t_fractol *f)
{
	if (ar == 'M')
		f->type = 'M';
	else if (ar == 'J')
		f->type = 'J';
	else if (ar == 'S')
		f->type = 'S';
	else if (ar == 'B')
		f->type = 'B';
	else if (ar == 'D')
		f->type = 'D';
	else if (ar == 'L')
		f->type = 'L';
	else
		ft_mega_return();
}

void	ft_mega_return(void)
{
	ft_putendl("Usage: ./fractol [M, J, S, B, D, L]");
	ft_putendl("M--->Mandelbrot\nJ--->Julia\nS--->Spider");
	ft_putendl("B--->Burning ship\nD--->Drop\nL--->Lambda");
	exit(-1);
}
