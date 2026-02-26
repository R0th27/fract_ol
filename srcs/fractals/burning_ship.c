/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:48:17 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 19:49:48 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	burning_ship(t_complex c, t_fractal *f)
{
	double		tmp;
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < f->max_iter)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		tmp = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = tmp;
		i++;
	}
	return (escape_speed(z, i));
}
