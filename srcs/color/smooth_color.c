/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:47 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 23:38:00 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int32_t	rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

static int32_t	psychedelic(double mu, t_fractal *f)
{
	double		t;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	t = mu / f->max_iter;
	t = pow(t, 0.7);
	t = t * 15.0 + f->colour_shift;
	r = sin(t) * 127 + 128;
	g = sin(t * 1.3 + 2) * 127 + 128;
	b = sin(t * 1.7 + 4) * 127 + 128;
	return (rgba(r, g, b, 255));
}

static int32_t	gradient(double mu, t_fractal *f)
{
	double		t;
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

int32_t	get_color(double mu, t_fractal *f)
{
	if (mu < 0)
		return (rgba(0, 0, 0, 255));
	if (f->colour_mode == PSYCHEDELIC)
		return (psychedelic(mu, f));
	return (gradient(mu, f));
}
