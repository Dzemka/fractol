/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:05:09 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 22:05:11 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_complex(long double a, long double b)
{
	t_complex	complex;

	complex.re = a;
	complex.im = b;
	return (complex);
}

int	ft_close(void )
{
	exit(0);
}

void	ft_error(void )
{
	ft_putstr_fd("Unavailable argument!\nAvailable arguments:\n", 1);
	ft_putstr_fd("mandelbrot, ", 1);
	ft_putstr_fd("julia, ", 1);
	ft_putstr_fd("burning_ship, ", 1);
	ft_putstr_fd("mandelbar, ", 1);
	ft_putstr_fd("experimental\n", 1);
}
