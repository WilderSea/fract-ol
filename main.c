/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:52:36 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/22 12:55:36 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	(void)argc;
	ft_check_argus(argc, argv, &fractal);
	ft_init_fractal(&fractal);
	ft_draw_fractal(&fractal);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	if (mlx_image_to_window(fractal.mlx, fractal.img, 0, 0) < 0)
	{
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(fractal.mlx, &ft_interactions, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
