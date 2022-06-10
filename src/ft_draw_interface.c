/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:03:36 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:03:39 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_print_fractal_color_shift(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 575, 30, 0xFF00FF,
		"Fractal color shift - \"A-L\" ");
	mlx_string_put(vars->mlx, vars->win, 575, 60, 0xFF0000,
		"\"A - Red\" ");
	mlx_string_put(vars->mlx, vars->win, 685, 60, 0x00FF00,
		"\"S - Green\" ");
	mlx_string_put(vars->mlx, vars->win, 575, 80, 0x0000FF,
		"\"D - Blue\" ");
	mlx_string_put(vars->mlx, vars->win, 685, 80, 0xFF00FF,
		"\"F - Fuchsia\" ");
	mlx_string_put(vars->mlx, vars->win, 575, 100, 0xFFFF00,
		"\"G - Yellow\" ");
	mlx_string_put(vars->mlx, vars->win, 685, 100, 0x00FFFF,
		"\"H - Light blue\" ");
	mlx_string_put(vars->mlx, vars->win, 575, 120, 0xFFFFFF,
		"\"J - Black\" ");
	mlx_string_put(vars->mlx, vars->win, 685, 120, 0xFFFFFF,
		"\"L - White\" ");
}

static void	ft_print_escape_color_shift(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 820, 30, 0xFF00FF,
		"Escape color shift - \"1-4\" ");
	mlx_string_put(vars->mlx, vars->win, 820, 60, 0xFFFFFF,
		"\"1 - Red - blue\" ");
	mlx_string_put(vars->mlx, vars->win, 820, 80, 0xFFFFFF,
		"\"2 - Green - blue\" ");
	mlx_string_put(vars->mlx, vars->win, 820, 100, 0xFFFFFF,
		"\"3 - Green - red\" ");
	mlx_string_put(vars->mlx, vars->win, 820, 120, 0xFFFFFF,
		"\"4 - Green - red - blue\" ");
}

static void	ft_print_move(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 750, 160, 0xFF00FF,
		"Move");
	mlx_string_put(vars->mlx, vars->win, 610, 190, 0x00FFFF,
		"Left arrow");
	mlx_string_put(vars->mlx, vars->win, 800, 190, 0x00FFFF,
		"Right arrow");
	mlx_string_put(vars->mlx, vars->win, 610, 210, 0x00FFFF,
		"Up arrow");
	mlx_string_put(vars->mlx, vars->win, 800, 210, 0x00FFFF,
		"Down arrow");
	mlx_string_put(vars->mlx, vars->win, 610, 230, 0x00FFFF,
		"Zoom in - scroll mouse up");
	mlx_string_put(vars->mlx, vars->win, 800, 230, 0x00FFFF,
		"Zoom out - scroll mouse down");
}

static void	ft_print_select_fractal(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 550, 290, 0xFF00FF,
		"Select fractal \"Z - B\"");
	mlx_string_put(vars->mlx, vars->win, 570, 330, 0x00FFFF,
		"Z - Mandelbrot");
	mlx_string_put(vars->mlx, vars->win, 570, 350, 0x00FFFF,
		"X - Julia");
	mlx_string_put(vars->mlx, vars->win, 570, 370, 0x00FFFF,
		"C - Burning_ship");
	mlx_string_put(vars->mlx, vars->win, 570, 390, 0x00FFFF,
		"V - Mandelbar");
	mlx_string_put(vars->mlx, vars->win, 570, 410, 0x00FFFF,
		"B - Experimental");
}

void	ft_draw_interface(t_vars *vars)
{
	ft_print_fractal_color_shift(vars);
	ft_print_escape_color_shift(vars);
	ft_print_move(vars);
	ft_print_select_fractal(vars);
	mlx_string_put(vars->mlx, vars->win, 805, 290, 0xFF00FF,
		"Other functions");
	mlx_string_put(vars->mlx, vars->win, 725, 330, 0x00FFFF,
		"Q - Iteration + 50");
	mlx_string_put(vars->mlx, vars->win, 725, 350, 0x00FFFF,
		"E - Iteration - 50");
	mlx_string_put(vars->mlx, vars->win, 725, 370, 0x00FFFF,
		"R - Reset");
	mlx_string_put(vars->mlx, vars->win, 725, 390, 0x00FFFF,
		"P - pause / play (for Julia fractal)");
	mlx_string_put(vars->mlx, vars->win, 730, 410, 0x00FFFF,
		"Esc - Close");
}
