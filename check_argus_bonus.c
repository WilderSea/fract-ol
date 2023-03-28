/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argus_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:56:12 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/23 12:28:58 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*

	Julia fractal may get arguments for the drawing.
	These argus will be saved in the fractal struct and used along the program.

*/

void	ft_print_usage(void)
{
	ft_putstr_fd("Usage : [program name] [fractal set] \
	optional[x coordinate] optional[y coordinate]\n", 1);
	ft_putstr_fd("Example : ./fractol mandelbrot\n", 1);
	ft_putstr_fd("Example : ./fractol julia -0.8 +0.156\n", 1);
	exit(1);
}

int	ft_check_use(char *argu)
{
	int	i;

	i = 0;
	if (argu[0] == '-' || argu[0] == '+')
	{
		i++;
	}
	while (argu[i])
	{
		if ((argu[i] < '0' || argu[i] > '9') && argu[i] != '.')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_params(int argc, char *arg2, char *arg3, t_fractal *fractal)
{
	if (argc > 2)
	{
		if (arg2)
		{
			if (ft_check_use(arg2) == 1)
				ft_print_usage();
			fractal->julia_real = ft_atof(arg2);
		}
		if (arg3)
		{
			if (ft_check_use(arg3) == 1)
				ft_print_usage();
			fractal->julia_img = ft_atof(arg3);
		}
	}
}

void	ft_check_argus(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		ft_print_usage();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->set = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->set = 2;
		ft_check_params(argc, argv[2], argv[3], fractal);
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
		fractal->set = 3;
	else
		ft_print_usage();
}
