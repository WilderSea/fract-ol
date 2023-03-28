/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:29:10 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/23 12:46:42 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*

    To draw the fractal, first we calculate the posicion x,y of each pixel
    in the complex plane.
    The complex number "c" will hold the result of that calculation (the position
    in the complex plane) and it has two values: real and imaginary.
    
    Each fractal algorithm will use this complex number to get the number of 
    iters needed to find out whether that position belongs to the fractal or not.
    Depending on that number, we will apply a different color, to show the 
    different levels of depth when creating the fractal.
    
*/

void	ft_draw_fractal(t_fractal *fractal)
{
	t_complex	c;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_calc_propor(fractal, x, y, &c);
			if (fractal->set == 1)
				fractal->color = ft_draw_mandelbrot(fractal, &c);
			else if (fractal->set == 2)
				fractal->color = ft_draw_julia(fractal, &c);
			else if (fractal->set == 3)
				fractal->color = ft_draw_burningship(fractal, &c);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			x++;
		}
		y++;
	}
}

/* 

Initializate values for the fractal struct and the MLX42 library. 
Set the limits for the complex plane, using Mandelbrot limits as reference.

*/

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "42 Fract-0l", false);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->max_iter = 150;
	fractal->min_real = -2;
	fractal->max_real = 1;
	fractal->max_img = 1;
	fractal->min_img = -1;
	fractal->iters = 0;
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
}
