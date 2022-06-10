/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:03:49 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:03:50 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_get_data_mlx(t_vars **vars)
{
	t_vars	*vars_ptr;

	vars_ptr = *vars;
	vars_ptr->mlx = mlx_init();
	if (!vars_ptr->mlx)
		exit (1);
	vars_ptr->win = mlx_new_window(vars_ptr->mlx, 1000, 500, "Fractol");
	if (!vars_ptr->win)
	{
		mlx_clear_window(vars_ptr->mlx, vars_ptr->win);
		free(vars_ptr->mlx);
		exit (1);
	}
	vars_ptr->img.img = NULL;
	*vars = vars_ptr;
}

void	ft_init_fractal_data(t_vars *vars)
{
	vars->rgb_in.r = 0;
	vars->rgb_in.g = 0;
	vars->rgb_in.b = 0;
	vars->rgb_out.r = 255;
	vars->rgb_out.g = 255;
	vars->rgb_out.b = 255;
	vars->max = ft_complex(2.0, 2.0);
	vars->min = ft_complex(-2.0, -2.0);
	vars->step = ft_complex((vars->max.re - vars->min.re) / WIDTH,
			(vars->max.im - vars->min.im) / HEIGHT);
	vars->max_iter = 50;
	vars->pause = 0;
}

void	ft_get_data_fractal(t_vars *vars_ptr, char *fractal_name)
{
	size_t	len;
	t_vars	*vars;

	vars = vars_ptr;
	len = ft_strlen(fractal_name);
	if (len == 5 && !ft_strncmp(fractal_name, "julia", len + 1))
		vars->formula = &ft_julia;
	else if (len == 10 && !ft_strncmp(fractal_name, "mandelbrot", len + 1))
		vars->formula = &ft_mandelbrot;
	else if (len == 12 && !ft_strncmp(fractal_name, "burning_ship", len + 1))
		vars->formula = &ft_burning_ship;
	else if (len == 9 && !ft_strncmp(fractal_name, "mandelbar", len + 1))
		vars->formula = &ft_mandelbar;
	else if (len == 12 && !ft_strncmp(fractal_name, "experimental", len + 1))
		vars->formula = &ft_experimental;
	else
	{
		ft_error();
		ft_close();
	}
	ft_init_fractal_data(vars);
}

void	ft_get_data(t_vars **vars, char *argv)
{
	ft_get_data_mlx(vars);
	ft_get_data_fractal(*vars, argv);
}
