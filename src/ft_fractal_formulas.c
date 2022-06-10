/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_formulas.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:05:30 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:05:32 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_set *set)
{
	set->z_new = ft_complex(set->sqr.re - set->sqr.im + set->cnst.re,
			2.0 * set->z.re * set->z.im + set->cnst.im);
}

void	ft_julia(t_set *set)
{
	set->z_new = ft_complex(set->sqr.re - set->sqr.im + set->julia_cnst.re,
			2.0 * set->z.re * set->z.im + set->julia_cnst.im);
}

void	ft_burning_ship(t_set *set)
{
	set->z_new = ft_complex(set->sqr.re - set->sqr.im + set->cnst.re,
			-2.0 * fabs((double)(set->z.re * set->z.im)) + set->cnst.im);
}

void	ft_mandelbar(t_set *set)
{
	set->z_new = ft_complex(set->sqr.re - set->sqr.im + set->cnst.re,
			-2.0 * set->z.re * set->z.im + set->cnst.im);
}

void	ft_experimental(t_set *set)
{
	set->z_new = ft_complex(tan(set->sqr.re - set->sqr.im) + set->cnst.re,
			tan(2.0 * set->z.re * set->z.im) + set->cnst.im);
}
