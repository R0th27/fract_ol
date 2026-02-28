/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:41:26 by htoe              #+#    #+#             */
/*   Updated: 2026/02/28 13:53:56 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_complex c, t_fractal *f)
{
	double		tmp;
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < f->max_iter)
	{
		tmp = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = tmp;
		i++;
	}
	return (precise_escape_point(z, i, f->max_iter));
}
