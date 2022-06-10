/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:41 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:04:43 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_fractal(int keycode, t_vars *vars)
{
	if (keycode == LEFT_ARR)
	{
		vars->max.re -= 100 * vars->step.re;
		vars->min.re -= 100 * vars->step.re;
	}
	if (keycode == RIGHT_ARR)
	{
		vars->max.re += 100 * vars->step.im;
		vars->min.re += 100 * vars->step.im;
	}
	if (keycode == UP_ARR)
	{
		vars->max.im += 100 * vars->step.im;
		vars->min.im += 100 * vars->step.im;
	}
	if (keycode == DOWN_ARR)
	{
		vars->max.im -= 100 * vars->step.im;
		vars->min.im -= 100 * vars->step.im;
	}
}
