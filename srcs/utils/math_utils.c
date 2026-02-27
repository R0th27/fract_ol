/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:09:15 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 17:50:18 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

double	ft_atod(char *s)
{
	double	result;
	double	sign;
	double	frac;

	result = 0;
	sign = 1;
	frac = 0.1;
	if (*s == '+' || *s == '-')
		sign = 44 - *s++;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			result += (*s++ - '0') * frac;
			frac *= 0.1;
		}
	}
	return (result * sign);
}
