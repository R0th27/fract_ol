/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:15:07 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 23:03:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	computing_fractal(t_fractal *f)
{
	t_matrix	para;
	t_complex	p;
	double		mu;

	if (!f->render.computing_row)
		update_iterations(f);
	para.i = f->render.computing_row * f->width;
	para.row = 40;
	while (para.row-- && f->render.computing_row < f->height)
	{
		para.x = -1;
		while (++para.x < f->width)
		{
			p = interpolation(para.x, f->render.computing_row, f);
			mu = iterate(p, f);
			f->mu_buf[para.i++] = mu;
		}
		f->render.computing_row++;
	}
	if (f->render.computing_row >= f->height)
	{
		f->render.computing_row = 0;
		f->render.need_recompute = 0;
		f->render.need_recolour = 1;
	}
}
