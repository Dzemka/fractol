/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:00:01 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:00:06 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->line_len + x * img->bpp / 8;
	*(int *)(pixel) = color;
}

static int	ft_render(t_vars *vars)
{
	t_complex	pos;
	int			x;
	int			y;

	pos = ft_complex(vars->min.re + vars->pos.re * vars->step.re,
			vars->max.im - vars->pos.im * vars->step.re);
	if (vars->formula == &ft_julia && !vars->pause)
		vars->julia_cnst = pos;
	y = -1;
	vars->c.im = vars->max.im;
	while (++y <= HEIGHT)
	{
		x = -1;
		vars->c.re = vars->min.re;
		while (++x <= WIDTH)
		{
			ft_pixel_put(&vars->img, x, y, ft_get_iter_color(vars));
			vars->c.re += vars->step.re;
		}
		vars->c.im -= vars->step.im;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_render_info(vars, &pos);
	return (0);
}

void	ft_draw(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	ft_draw_interface(vars);
	mlx_loop_hook(vars->mlx, &ft_render, vars);
}
