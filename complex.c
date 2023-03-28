/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:48:54 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/22 19:12:09 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
    This function receives the x and y values of each pixel across the window 
    image and calculates the complex number "c" in the real / imaginary plane.
    
    c = x + yi;
    
    To calculate this we have to overlap the window image and the complex plane,
    and find put the proportion with a rule of three.
    
    For this program, we use Mandelbrot proportions as the complex plane.

*/

void	ft_calc_propor(t_fractal *fractal, double x, double y, t_complex *c)
{
	if (fractal->set == 1 || fractal->set == 3)
	{
		c->real = fractal->min_real + (x * ((fractal->max_real - \
						fractal->min_real) / WIDTH));
		c->imaginary = fractal->max_img - (y * ((fractal->max_img - \
						fractal->min_img) / HEIGHT));
	}
	else if (fractal->set == 2)
	{
		c->real = fractal->min_real + (x * ((fractal->max_real - \
						fractal->min_real) / WIDTH) + 0.5);
		c->imaginary = fractal->max_img - (y * ((fractal->max_img - \
						fractal->min_img) / HEIGHT));
	}
}
