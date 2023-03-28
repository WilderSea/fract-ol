/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:11:20 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/22 18:52:31 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
    Algorithm for plotting the Mandelbrot set:
    In the "escape time algorithm", a repeating calculation is performed for 
    each x,y point in the window area and based on the result of that 
	calculation, a color is chosen for that pixel.

    For drawing the Mandelbrot set, we previously have set the pixel as a 
    complex number, iterating through every pixel and calculating their 
    corresponding complex number, that result is saved in c->real for real part 
    and c->imaginary for imaginary part.
    Calculate the Mandelbrot function:
    z = z*z + c where c is a complex number.
    
    Then we colour the pixel whether it belongs to the set or not.
    z2_real--> temporary variable only needed for the algorithm. Real axis only.

    *********************************************

          Z(0) = 0 + c                 Start

          Z(n + 1) = Z2(n) + c       Recursion

    *********************************************
    
*/

int	ft_mandelbrot(t_fractal *fractal, t_complex *c)
{
	t_complex	z;
	double		z2_real;
	int			iters;

	z.real = 0;
	z.imaginary = 0;
	z2_real = 0;
	iters = 0;
	while (iters < fractal->max_iter)
	{
		z2_real = (z.real * z.real) - (z.imaginary * z.imaginary) + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = z2_real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
		{
			break ;
		}
		iters++;
	}
	return (iters);
}

uint32_t	ft_draw_mandelbrot(t_fractal *fractal, t_complex *c)
{
	fractal->color = 0xFFFFFFFF;
	fractal->iters = ft_mandelbrot(fractal, c);
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
