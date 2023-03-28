/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:15:43 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/22 17:48:35 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
    Range of colors depending on the number of iterations.
*/

uint32_t	ft_get_color(int num_iters)
{
	uint32_t	color;

	color = 0xffffffFF;
	if (num_iters < 5)
		color = 0xef605fFF;
	else if (num_iters < 10)
		color = 0xFF9944FF;
	else if (num_iters < 15)
		color = 0xFFF500FF;
	else if (num_iters < 20)
		color = 0x5fefa8FF;
	else if (num_iters < 25)
		color = 0xa6ef5fFF;
	else if (num_iters < 30)
		color = 0x5fa6efFF;
	else if (num_iters < 35)
		color = 0xa85fefFF;
	else if (num_iters < 40)
		color = 0x8219e8FF;
	else if (num_iters < 45)
		color = 0xFF00FFFF;
	else
		color = 0xef5fa6FF;
	return (color);
}
