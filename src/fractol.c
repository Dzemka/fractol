/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:58:18 by olugash           #+#    #+#             */
/*   Updated: 2022/06/10 21:58:28 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof (t_vars));
	if (!vars)
		return (1);
	if (argc != 2)
	{
		ft_error();
		free(vars);
		return (1);
	}
	ft_get_data(&vars, argv[1]);
	ft_draw(vars);
	ft_hook_manager(&vars);
	mlx_loop((vars)->mlx);
}
