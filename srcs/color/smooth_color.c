/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:55:47 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 13:25:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	clamp(double x)
{
	if (x < 0)
		x = 0;
	if (x > 1)
		x = 1;
	return ((int)(x * 255.0 + 0.5));
}

static int	colour_generator(double t, t_palette p)
{
	double	r;
	double	g;
	double	b;

	r = p.a[0] + (p.b[0] * cos(6.28318 * (p.c[0] * t + p.d[0])));
	g = p.a[1] + (p.b[1] * cos(6.28318 * (p.c[1] * t + p.d[1])));
	b = p.a[2] + (p.b[2] * cos(6.28318 * (p.c[2] * t + p.d[2])));
	return (clamp(r) << 24 | clamp(g) << 16 | clamp(b) << 8 | 255);
}

static int	get_colour(t_fractal *f, int i)
{
	double	t;

	t = f->mu_buf[i];
	if (t < 0)
		return (0 << 24 | 0 << 16 | 0 << 8 | 255);
	t = (t + f->colour_shift) * f->colour_scale;
	t = fmod(t, 1.0);
	return (colour_generator(t, f->pal));
}

void	colouring(t_fractal *f)
{
	t_matrix	para;
	int			colour;

	para.i = 0;
	para.row = -1;
	while (++para.row < f->height)
	{
		para.x = -1;
		while (++para.x < f->width)
		{
			colour = get_colour(f, para.i);
			mlx_put_pixel(f->img, para.x, para.row, colour);
			para.i++;
		}
	}
	f->render.need_recolour = 0;
}
