/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:09:15 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 18:10:16 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
