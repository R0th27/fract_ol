/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:15:07 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 06:27:21 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	computing_fractal(t_fractal *f)
{
	int			x;
	int			y;
	t_complex	p;
	double		mu;
	int			i;

	update_iterations(f);
	i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			p = interpolation(x, y, f);
			mu = iterate(p, f);
			f->mu_buf[i++] = mu;
		}
	}
}
