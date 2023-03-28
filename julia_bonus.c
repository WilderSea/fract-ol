/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:51:03 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/23 11:40:32 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
    Julia fractal generates a different shape depending on the starting point.
    
    In this case, the complex number "c" will be a "constant" and corresponds 
    to the arguments received during the execution of the program.
    
    "z" will hold the values of the calculated complex number for each pixel.

    The result of the function will be the number of iters needed to determine
    if that pixel belongs or not the julia set and we will color it accordingly.
    
	z2_real--> temporary variable only needed for the algorithm. Real axis only.

    **********************

        f(z) = z2 + c

    **********************
*/

int	ft_julia(t_fractal *fractal, t_complex *c)
{
	t_complex	z;
	double		z2_real;
	t_complex	constant;

	fractal->iters = 0;
	z = *c;
	z2_real = c->real;
	if (fractal->julia_real)
		constant.real = fractal->julia_real;
	else
		constant.real = -0.8;
	if (fractal->julia_img)
		constant.imaginary = fractal->julia_img;
	else
		constant.imaginary = +0.156;
	while (fractal->iters < fractal->max_iter)
	{
		z2_real = (z.real * z.real) - (z.imaginary * z.imaginary);
		z.imaginary = 2 * z.real * z.imaginary + constant.imaginary;
		z.real = z2_real + constant.real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 16)
			break ;
		fractal->iters++;
	}
	return (fractal->iters);
}

uint32_t	ft_draw_julia(t_fractal *fractal, t_complex *c)
{
	fractal->color = 0xFFFFFFFF;
	fractal->iters = ft_julia(fractal, c);
	if (fractal->iters == fractal->max_iter)
	{
		fractal->color = 0x2f2f2fFF;
	}
	else
	{
		fractal->color = ft_get_color(fractal->iters);
	}
	return (fractal->color);
}
