/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:38:14 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 19:56:02 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
