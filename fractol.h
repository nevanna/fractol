/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:53:12 by htillman          #+#    #+#             */
/*   Updated: 2019/03/06 17:33:48 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "pthread.h"

typedef struct	s_img
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*adr;
	int			width;
	int			height;
	int			bitspp;
	int			size_line;
	int			endian;
	double		zoom;
	double		movex;
	double		movey;
	char		*titel;
}				t_img;
typedef struct	s_julia
{
	double		c_re;
	double		c_im;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	int			color;
	int			max_iter;
	double		pr;
	double		pi;
}				t_julia;
typedef struct	s_x
{
	int			x;
	int			y;
	int			color;
}				t_x;
typedef struct	s_fractol
{
	char		type;
	char		*titel;
	int			xwin;
	int			ywin;
	int			xpr;
	int			ypr;
	t_img		img;
	t_julia		set;
	int			yw_start;
	int			yw_end;
	int			t;
	int			sp_flag;
	int			mv_flag;
	int			s_col;
	int			j_col_f;
	int			j_col_s;
	int			m_col;
	int			b_col_f;
	int			b_col_s;
	int			b_col_t;
	int			scheme;
	int			l_color;
	char		*str_error_f;
	char		*str_error_s;
	char		*str_error_t;
	double		lam;
}				t_fractol;

int				main(int argc, char **argv);
void			ft_try_draw(t_img	*img, t_x l);
void			ft_key(t_img *img, t_fractol *f);
void			ft_put(t_img *img, t_fractol *f);
int				ft_change_c(int x, int y, t_fractol *f);
void			*ft_ju(void *data);
void			thr_julia(t_fractol *f);
void			thr_mandel(t_fractol *f);
void			*ft_mal(void *data);
void			thr_spider(t_fractol *f);
void			*ft_spi(void *data);
void			thr_br_sh(t_fractol *f);
void			*ft_b_s(void *data);
void			thr_lambda(t_fractol *f);
void			*ft_lam(void *data);
void			thr_drop(t_fractol *f);
void			*ft_drop(void *data);
int				ft_change_c(int x, int y, t_fractol *f);
int				ft_zoom_point(int but, int x, int y, t_fractol *f);
void			ft_what(t_fractol *f);
void			image_set_pixel(t_img *image, int x, int y, int color);
int				ft_iter_down(t_fractol *f);
int				ft_iter_up(t_fractol *f);
int				ft_up(t_fractol *f);
int				ft_down(t_fractol *f);
int				ft_left(t_fractol *f);
int				ft_right(t_fractol *f);
int				ft_color(t_fractol *f);
void			ft_initt(t_fractol *f);
int				ft_start(t_fractol *f);
void			ft_get_new_ar_l(char ***argv_list, char *a, char *c);
void			ft_call(int argc, char **argv, t_fractol *f);
void			ft_argc(int argc, char **argv, t_fractol *f);
void			ft_img(t_img	*img);
void			ft_titel(t_fractol *f);
void			ft_is_that(char ar, t_fractol *f);
void			ft_mega_return(void);
void			ft_init(t_fractol *f);

#endif
