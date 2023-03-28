/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:04:04 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/23 12:25:04 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*

Burning Ship fractal difference with Mandelbrot set is that the real and 
imaginary components are set to their respective absolute values before 
squaring at each iteration.

*/

int	ft_burningship(t_fractal *fractal, t_complex *c)
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
		z.imaginary = fabs(2 * z.real * z.imaginary) + c->imaginary;
		z.real = z2_real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
		{
			break ;
		}
		iters++;
	}
	return (iters);
}

uint32_t	ft_draw_burningship(t_fractal *fractal, t_complex *c)
{
	fractal->color = 0xFFFFFFFF;
	fractal->iters = ft_burningship(fractal, c);
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
