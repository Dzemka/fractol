/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:58 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:05:01 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_fractal(int key, t_vars *vars)
{
	if (key == KEY_Z)
		ft_get_data_fractal(vars, "mandelbrot");
	if (key == KEY_X)
		ft_get_data_fractal(vars, "julia");
	if (key == KEY_C)
		ft_get_data_fractal(vars, "burning_ship");
	if (key == KEY_V)
		ft_get_data_fractal(vars, "mandelbar");
	if (key == KEY_B)
		ft_get_data_fractal(vars, "experimental");
}
