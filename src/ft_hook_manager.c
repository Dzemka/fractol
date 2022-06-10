/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:22 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:15:41 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_is_color_change(int k, t_vars *vars)
{
	if (k == D_1 || k == D_2 || k == D_3 || k == D_4)
		ft_color_shift(k, vars);
	if (k == KEY_A || k == KEY_S || k == KEY_D
		|| k == KEY_F || k == KEY_G || k == KEY_H)
		ft_color_shift(k, vars);
}

static int	key_hook(int k, t_vars *vars)
{
	if (k == ESC)
		exit (0);
	ft_is_color_change(k, vars);
	if (k == KEY_R)
		ft_init_fractal_data(vars);
	if (k == KEY_Z || k == KEY_X || k == KEY_C || k == KEY_V || k == KEY_B)
		ft_select_fractal(k, vars);
	if (k == LEFT_ARR || k == RIGHT_ARR || k == UP_ARR || k == DOWN_ARR)
		ft_move_fractal(k, vars);
	if (k == KEY_Q)
		vars->max_iter += 50;
	if (k == KEY_E && vars->max_iter > 50)
		vars->max_iter -= 50;
	if (k == KEY_P && vars->pause == 0)
		vars->pause = 1;
	else if (k == KEY_P && vars->pause == 1)
		vars->pause = 0;
	return (0);
}

static int	ft_mouse_hook(int button, int x, int y, t_vars *vars)
{
	long double	zoom;
	t_complex	move;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (button == SCROLL_UP)
			zoom = 1.1;
		else
			zoom = 0.9;
		move = ft_complex(vars->min.re + x * vars->step.re,
				vars->max.im - y * vars->step.im);
		vars->step = ft_complex((vars->max.re - vars->min.re) / WIDTH / zoom,
				(vars->max.im - vars->min.im) / HEIGHT / zoom);
		vars->min = ft_complex(move.re - x * vars->step.re,
				move.im - (HEIGHT - y) * vars->step.im);
		vars->max = ft_complex(move.re + (WIDTH - x) * vars->step.re,
				move.im + y * vars->step.im);
	}
	return (0);
}

int	ft_get_mouse_pos(int x, int y, t_vars *vars)
{
	vars->pos = ft_complex((long double)x, (long double)y);
	return (0);
}

void	ft_hook_manager(t_vars **vars)
{
	mlx_key_hook((*vars)->win, &key_hook, *vars);
	mlx_mouse_hook((*vars)->win, &ft_mouse_hook, *vars);
	mlx_hook((*vars)->win, 17, 0, &ft_close, vars);
	mlx_hook((*vars)->win, 6, 0, &ft_get_mouse_pos, *vars);
}
