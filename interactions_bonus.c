/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:49:28 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/22 18:51:09 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	mlx_loop_hook executes a function per frame, we use it to regenerate the
	fractal whenever there is user interaction: scroll, key presses...
	
	ydelta > 0 Up!
	ydelta < 0 Down!
*/

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	xdelta = 0;
	if (ydelta > 0)
	{
		fractal->min_real += 0.1;
		fractal->max_real -= 0.1;
		fractal->min_img += 0.06;
		fractal->max_img -= 0.06;
	}
	else if (ydelta < 0)
	{
		fractal->min_real -= 0.1;
		fractal->max_real += 0.1;
		fractal->min_img -= 0.06;
		fractal->max_img += 0.06;
	}
	ft_draw_fractal(fractal);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(fractal->mlx);
	}
}

/* 

Main function to gather all the functions for the interactions.

void *param must get the fractal struct values.

*/

void	ft_interactions(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	mlx_scroll_hook(fractal->mlx, &my_scrollhook, fractal);
	mlx_key_hook(fractal->mlx, &my_keyhook, fractal);
}
