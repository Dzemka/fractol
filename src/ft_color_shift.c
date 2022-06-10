/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_shift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:58:58 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 21:59:00 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_color_shift_out(int key, t_vars *vars)
{
	if (key == D_1)
		ft_set_color_out(255, 0, 255, vars);
	if (key == D_2)
		ft_set_color_out(0, 255, 255, vars);
	if (key == D_3)
		ft_set_color_out(255, 255, 0, vars);
	if (key == D_4)
		ft_set_color_out(255, 255, 255, vars);
}

static void	ft_color_shift_in(int key, t_vars *vars)
{
	if (key == KEY_A)
		ft_set_color_in(255, 0, 0, vars);
	if (key == KEY_S)
		ft_set_color_in(0, 255, 0, vars);
	if (key == KEY_D)
		ft_set_color_in(0, 0, 255, vars);
	if (key == KEY_F)
		ft_set_color_in(255, 0, 255, vars);
	if (key == KEY_G)
		ft_set_color_in(255, 255, 0, vars);
	if (key == KEY_H)
		ft_set_color_in(0, 255, 255, vars);
	if (key == KEY_J)
		ft_set_color_in(0, 0, 0, vars);
	if (key == KEY_K)
		ft_set_color_in(255, 255, 255, vars);
}

void	ft_color_shift(int key, t_vars *vars)
{
	if (key == D_1 || key == D_2 || key == D_3 || key == D_4)
		ft_color_shift_out(key, vars);
	if (key == KEY_A || key == KEY_S || key == KEY_D
		|| key == KEY_F || key == KEY_G || key == KEY_H)
		ft_color_shift_in(key, vars);
}
