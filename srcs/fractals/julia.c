/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:45:57 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 22:07:35 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	julia(t_complex z, t_fractal *f)
{
	double		tmp;
	t_complex	c;
	int			i;

	c.r = f->julia_cr;
	c.i = f->julia_ci;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < f->max_iter)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = tmp;
		i++;
	}
	return (escape_speed(z, i, f->max_iter));
}
