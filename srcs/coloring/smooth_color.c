/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:47 by htoe              #+#    #+#             */
/*   Updated: 2026/02/28 15:14:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	time_animate(t_fractal *f)
{
	double	now;
	double	delta;

	now = get_time();
	delta = now - f->last_time;
	f->last_time = now;
	if (delta > 0.05)
		delta = 0.05;
	if (!f->render.need_recompute)
	{
		f->anim_phase += f->palette_speed * delta;
		f->render.need_recolour = 1;
	}
}

static uint32_t	clamp(double x)
{
	if (x < 0)
		x = 0;
	if (x > 1)
		x = 1;
	return ((uint32_t)(x * 255.0 + 0.5));
}

static uint32_t	colour_generator(double t, t_palette p)
{
	double	r;
	double	g;
	double	b;

	r = p.a[0] + (p.b[0] * cos(6.28318 * (p.c[0] * t + p.d[0])));
	g = p.a[1] + (p.b[1] * cos(6.28318 * (p.c[1] * t + p.d[1])));
	b = p.a[2] + (p.b[2] * cos(6.28318 * (p.c[2] * t + p.d[2])));
	return (255 << 24 | clamp(b) << 16 | clamp(g) << 8 | clamp(r));
}

static uint32_t	get_colour(t_fractal *f, int i)
{
	double	t;
	double	shift;

	t = f->mu_buf[i];
	if (t < 0)
		return (255 << 24 | 0 << 16 | 0 << 8 | 0);
	shift = f->colour_shift;
	if (f->anim_toggle == ANIM_ON)
		shift += f->anim_phase;
	t = (t + shift) * f->colour_scale;
	t = fmod(t, 1.0);
	return (colour_generator(t, f->palette));
}

void	colouring(t_fractal *f)
{
	t_matrix	para;
	int			colour;
	uint32_t	*px;

	px = (uint32_t *)f->img->pixels;
	para.i = 0;
	para.row = -1;
	while (++para.row < f->height)
	{
		para.x = -1;
		while (++para.x < f->width)
		{
			colour = get_colour(f, para.i);
			px[para.i++] = colour;
		}
	}
	f->render.need_recolour = 0;
}
