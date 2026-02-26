/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:47 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 20:33:53 by htoe             ###   ########.fr       */
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
	int32_t	r;
	int32_t	g;
	int32_t	b;

	t = (mu * 0.15) + f->colour_shift;
	r = sin(t) * 127 + 128;
	g = sin(t * 1.3 + 2) * 127 + 128;
	b = sin(t * 1.7 + 4) * 127 + 128;
	return (rgba(r, g, b, 255));
}

static int32_t	gradient(double mu, t_fractal *f)
{
	double	t;
	int32_t	r;
	int32_t	g;
	int32_t	b;

	t = (mu * 0.05) + f->colour_shift;
	r = (sin(t) + 1) * 127;
	g = (sin(t + 2.0) + 1) * 127;
	b = (sin(t + 4.0) + 1) * 127;
	return (rgba(r, g, b, 255));
}

double	escape_speed(t_complex z, int iter)
{
	double	mod;

	if (iter <= 0)
		return (iter);
	mod = (z.r * z.r) + (z.i * z.i);
	return (iter + 1 - log2(log(mod) / 2.0));
}

int32_t	get_color(double mu, t_fractal *f)
{
	if (f->colour_mode == PSYCHEDELIC)
		return (psychedelic(mu, f));
	return (gradient(mu, f));
}
