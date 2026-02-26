/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:47 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 22:30:01 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t	rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

static int32_t	psychedelic(double mu, t_fractal *f)
{
	double	t;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	t = mu / f->max_iter;
	t = pow(t, 0.7);
	t = t * 20.0 + f->colour_shift;
	r = sin(t) * 127 + 128;
	g = sin(t * 1.3 + 2) * 127 + 128;
	b = sin(t * 1.7 + 4) * 127 + 128;
	return (rgba(r, g, b, 255));
}

static int32_t	gradient(double mu, t_fractal *f)
{
	double	t;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	t = mu / f->max_iter;
	t = log(1.0 + 9.0 * t) / log(10.0);
	t = t * 8.0 + f->colour_shift;
	r = (sin(t) * 127) + 128;
	g = (sin(t + 2.094) * 127) + 128;
	b = (sin(t + 4.188) * 127) + 128;
	return (rgba(r, g, b, 255));
}

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

int32_t	get_color(double mu, t_fractal *f)
{
	if (mu < 0)
		return (rgba(0, 0, 0, 255));
	if (f->colour_mode == PSYCHEDELIC)
		return (psychedelic(mu, f));
	return (gradient(mu, f));
}
