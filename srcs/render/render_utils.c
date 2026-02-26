/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:38:14 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 23:36:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	escape_speed(t_complex z, int iter, int max_iter)
{
	double	mod;

	if (iter == max_iter)
		return (-1.0);
	if (iter == 0)
		return (0);
	mod = (z.r * z.r) + (z.i * z.i);
	return (iter + 1 - log(log(mod)) / log(2.0));
}

double	iterate(t_complex p, t_fractal *f)
{
	if (f->type == MANDELBROT)
		return (mandelbrot(p, f));
	else if (f->type == JULIA)
		return (julia(p, f));
	return (burning_ship(p, f));
}

t_complex	interpolation(int x, int y, t_fractal *f)
{
	t_complex	c;

	c.r = (x - WIDTH / 2.0) / f->zoom + f->offset_x;
	c.i = (y - HEIGHT / 2.0) / f->zoom + f->offset_y;
	return (c);
}

void	update_iterations(t_fractal *f)
{
	f->max_iter = 50 + (int)(30 * log10(f->zoom));
}
