/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 06:42:53 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 18:10:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_palette	get_deepspace_palette(void)
{
	t_palette	p;

	p.a[0] = 0.45;
	p.a[1] = 0.45;
	p.a[2] = 0.55;
	p.b[0] = 0.55;
	p.b[1] = 0.45;
	p.b[2] = 0.35;
	p.c[0] = 1.0;
	p.c[1] = 1.2;
	p.c[2] = 1.4;
	p.d[0] = 0.3;
	p.d[1] = 0.2;
	p.d[2] = 0.1;
	return (p);
}

static t_palette	get_ocean_palette(void)
{
	t_palette	p;

	p.a[0] = 0.15;
	p.a[1] = 0.35;
	p.a[2] = 0.55;
	p.b[0] = 0.25;
	p.b[1] = 0.45;
	p.b[2] = 0.45;
	p.c[0] = 0.8;
	p.c[1] = 1.0;
	p.c[2] = 1.2;
	p.d[0] = 0.55;
	p.d[1] = 0.25;
	p.d[2] = 0.15;
	return (p);
}

static t_palette	get_gradient_palette(void)
{
	t_palette	p;

	p.a[0] = 0.30;
	p.a[1] = 0.35;
	p.a[2] = 0.45;
	p.b[0] = 0.70;
	p.b[1] = 0.60;
	p.b[2] = 0.55;
	p.c[0] = 0.9;
	p.c[1] = 1.2;
	p.c[2] = 1.6;
	p.d[0] = 0.00;
	p.d[1] = 0.15;
	p.d[2] = 0.25;
	return (p);
}

static t_palette	get_psy_palette(void)
{
	t_palette	p;

	p.a[0] = 0.5;
	p.a[1] = 0.5;
	p.a[2] = 0.5;
	p.b[0] = 0.9;
	p.b[1] = 0.7;
	p.b[2] = 0.9;
	p.c[0] = 2.5;
	p.c[1] = 1.5;
	p.c[2] = 3.5;
	p.d[0] = 0.0;
	p.d[1] = 0.33;
	p.d[2] = 0.67;
	return (p);
}

void	update_palette(t_fractal *f)
{
	if (f->colour_mode == GRADIENT)
		f->pal = get_gradient_palette();
	else if (f->colour_mode == PSYCHEDELIC)
		f->pal = get_psy_palette();
	else if (f->colour_mode == OCEAN)
		f->pal = get_ocean_palette();
	else
		f->pal = get_deepspace_palette();
}
