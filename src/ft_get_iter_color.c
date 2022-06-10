/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_iter_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:03 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:04:04 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_iter_color(t_vars *vars)
{
	t_set	set;

	vars->iter = 0;
	set.z = vars->c;
	set.cnst = vars->c;
	set.julia_cnst = vars->julia_cnst;
	set.sqr = ft_complex(set.z.re * set.z.re, set.z.im * set.z.im);
	while (vars->iter < vars->max_iter && set.sqr.re + set.sqr.im <= 4)
	{
		set.sqr = ft_complex(set.z.re * set.z.re, set.z.im * set.z.im);
		vars->formula(&set);
		set.z = set.z_new;
		vars->iter++;
	}
	vars->z = set.z.re * set.z.re + vars->c.re
		+ set.z.im * set.z.im + vars->c.im;
	return (get_color(vars));
}
