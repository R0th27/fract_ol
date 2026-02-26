/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:15:07 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 20:24:40 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractal *f)
{
	int			x;
	int			y;
	t_complex	p;
	double		mu;
	int			color;

	(void)color;
	update_iterations(f);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			p = interpolation(x, y, f);
			mu = iterate(p, f);
			color = get_color(mu, f);
			mlx_put_pixel(f->img, x, y, color);
		}
	}
}
