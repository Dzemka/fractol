/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:05:56 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:05:57 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define WIDTH 500
# define HEIGHT 500
# ifdef __linux__

//linux keys
#  define ESC 65307
#  define LEFT_ARR 65361
#  define RIGHT_ARR 65363
#  define DOWN_ARR 65364
#  define UP_ARR 65362
#  define D_1 49
#  define D_2 50
#  define D_3 51
#  define D_3 52
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_H 104
#  define KEY_J 103
#  define KEY_K 107
#  define KEY_B 98
#  define KEY_C 99
#  define KEY_E 101
#  define KEY_P 112
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_V 118
#  define KEY_X 120
#  define KEY_Z 122
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
# else
//mac os keys
#  define ESC 53
#  define LEFT_ARR 123
#  define RIGHT_ARR 124
#  define DOWN_ARR 125
#  define UP_ARR 126
#  define D_1 18
#  define D_2 19
#  define D_3 20
#  define D_4 21
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_H 4
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_B 11
#  define KEY_C 8
#  define KEY_E 14
#  define KEY_P 35
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_V 9
#  define KEY_X 7
#  define KEY_Z 6
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
# endif

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_complex
{
	long double	re;
	long double	im;
}	t_complex;

typedef struct s_set
{
	t_complex	z;
	t_complex	z_new;
	t_complex	cnst;
	t_complex	julia_cnst;
	t_complex	sqr;
}	t_set;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	long double	iter;
	t_img		img;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	pos;
	t_complex	move;
	t_complex	julia_cnst;
	long double	z;
	long double	max_iter;
	t_complex	step;
	int			pause;
	t_rgb		rgb_in;
	t_rgb		rgb_out;
	void		(*formula)(struct s_set *set);
}	t_vars;

//data
void		ft_get_data_fractal(t_vars *vars, char *fractal_name);
void		ft_init_fractal_data(t_vars *vars);
void		ft_get_data(t_vars **vars, char *argv);

//fractal formulas
void		ft_mandelbrot(t_set *set);
void		ft_julia(t_set *set);
void		ft_burning_ship(t_set *set);
void		ft_mandelbar(t_set *set);
void		ft_experimental(t_set *set);

//hooks
void		ft_hook_manager(t_vars **vars_s);
void		ft_color_shift(int key, t_vars *vars);
void		ft_move_fractal(int key, t_vars *vars);
void		ft_select_fractal(int key, t_vars *vars);

//utils
int			ft_close(void );
void		ft_error(void );
t_complex	ft_complex(long double a, long double b);

//color
int			ft_get_iter_color(t_vars *vars);
int			get_color(t_vars *vars);
void		ft_set_color_out(int r, int g, int b, t_vars *vars);
void		ft_set_color_in(int r, int g, int b, t_vars *vars);

//draw
void		ft_draw(t_vars *vars);
void		ft_draw_interface(t_vars *vars);
void		ft_render_info(t_vars *vars, t_complex *pos);

#endif
