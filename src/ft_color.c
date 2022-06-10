/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:58:40 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 21:58:46 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_set_color_in(int r, int g, int b, t_vars *vars)
{
	vars->rgb_in.r = r;
	vars->rgb_in.g = g;
	vars->rgb_in.b = b;
}

void	ft_set_color_out(int r, int g, int b, t_vars *vars)
{
	vars->rgb_out.r = r;
	vars->rgb_out.g = g;
	vars->rgb_out.b = b;
}

int	get_color(t_vars *vars)
{
	long double	nu;
	long double	t;
	int			red;
	int			green;
	int			blue;

	if (vars->iter == 0)
		return (0x0);
	if (vars->iter == vars->max_iter)
		return (create_rgb(vars->rgb_in.r, vars->rgb_in.g, vars->rgb_in.b));
	nu = (log(log(vars->z) / 2 / log(2)) / log(2));
	vars->iter = vars->iter + 1 - nu;
	t = vars->iter / vars->max_iter;
	red = (int)(9 * (1 - t) * t * t * t * vars->rgb_out.r);
	green = (int)(6 * (1 - t) * (1 - t) * t * t * vars->rgb_out.g);
	blue = (int)(3 * (1 - t) * (1 - t) * (1 - t) * t * vars->rgb_out.b);
	return (create_rgb(red, green, blue));
}
