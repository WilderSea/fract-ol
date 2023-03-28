/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:29:50 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/23 11:44:28 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H 

# include "./Libs/libft/libft.h"
# include "./Libs/mlx42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 1200
# define HEIGHT 800 

/*
    Struct to hold all the values needed to generate a fractal
*/

typedef struct s_fractal
{
	int			set;
	int			max_iter;
	int			iters;
	uint32_t	color;
	double		min_real;
	double		max_real;
	double		min_img;
	double		max_img;
	double		julia_real;
	double		julia_img;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_fractal;

/*
    Struct for the position in the complex plane: 
    real axis -> x; imaginary axis -> y
*/

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

// Functions
void		ft_check_argus(int argc, char **argv, t_fractal *fractal);
void		ft_init_fractal(t_fractal *data);
void		ft_draw_fractal(t_fractal *data);
void		ft_calc_propor(t_fractal *data, double x, double y, t_complex *c);
uint32_t	ft_get_color(int num_iters);

// Fractals Drawing
uint32_t	ft_draw_mandelbrot(t_fractal *data, t_complex *c);
int			ft_mandelbrot(t_fractal *data, t_complex *c);
uint32_t	ft_draw_julia(t_fractal *data, t_complex *c);
int			ft_julia(t_fractal *data, t_complex *c);
uint32_t	ft_draw_burningship(t_fractal *fractal, t_complex *c);
int			ft_burningship(t_fractal *fractal, t_complex *c);

// Utils
int			ft_strcmp(const char *s1, const char *s2);
double		ft_atof(char *str);

// Events
void		ft_interactions(void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);

#endif
