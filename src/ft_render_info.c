/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:50 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:04:52 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*ft_get_coord(double fractional, double whole)
{
	char	*str;
	char	*whole_s;
	char	*fractional_s;
	char	*tmp;
	char	*minus;

	tmp = ft_itoa((fabs(whole)));
	if (fractional < 0)
	{
		minus = ft_strjoin("-", tmp);
		free(tmp);
		tmp = ft_strdup(minus);
		free(minus);
	}
	whole_s = ft_strjoin(tmp, ".");
	fractional_s = ft_itoa(fabs((fractional * 1000000)));
	free(tmp);
	str = ft_strjoin(whole_s, fractional_s);
	free(whole_s);
	free(fractional_s);
	return (str);
}

static void	ft_print_info(t_vars *vars,
		t_complex fractional_part, double whole_x, double whole_y)
{
	char	*coord_x;
	char	*coord_y;
	char	*max_iter;

	coord_x = ft_get_coord(fractional_part.re, whole_x);
	coord_y = ft_get_coord(fractional_part.im, whole_y);
	max_iter = ft_itoa((int)(vars->max_iter));
	if (coord_x && coord_y && max_iter)
	{
		mlx_string_put(vars->mlx, vars->win, 15, 20, 0xFF00FF, "x: ");
		mlx_string_put(vars->mlx, vars->win, 35, 20, 0xFF00FF, coord_x);
		mlx_string_put(vars->mlx, vars->win, 100, 20, 0xFF00FF, "y: ");
		mlx_string_put(vars->mlx, vars->win, 120, 20, 0xFF00FF, coord_y);
		mlx_string_put(vars->mlx, vars->win, 190, 20, 0xFF00FF, "iterations: ");
		mlx_string_put(vars->mlx, vars->win, 270, 20, 0xFF00FF, max_iter);
	}
	if (coord_x)
		free(coord_x);
	if (coord_y)
		free(coord_y);
	if (max_iter)
		free(max_iter);
}

void	ft_render_info(t_vars *vars, t_complex *pos)
{
	t_complex	fractional;
	double		whole_x;
	double		whole_y;

	fractional.re = modf(pos->re, &whole_x);
	fractional.im = modf(pos->im, &whole_y);
	ft_print_info(vars, fractional, whole_x, whole_y);
}
