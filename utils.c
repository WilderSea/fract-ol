/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:02:02 by msintas-          #+#    #+#             */
/*   Updated: 2023/03/22 18:31:39 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

double	ft_atof(char *str)
{
	double	result;
	double	neg;
	int		decimal;

	result = 0;
	neg = 1;
	decimal = 0;
	if (*str == '-' || *str == '+')
		if (*str == '-')
			neg = -1;
		str++;
	while (*str)
	{
		if (*str == '.')
			decimal = 1;
		if (*str >= '0' && *str <= '9')
		{
			if (decimal == 1)
				neg /= 10.00;
			result = (result * 10.00) + (*str - '0');
		}
		str++;
	}
	return (result * neg);
}
