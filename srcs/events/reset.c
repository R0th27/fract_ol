/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:54:43 by htoe              #+#    #+#             */
/*   Updated: 2026/02/28 15:04:29 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_window(t_fractal *f, t_reset mode)
{
	if (mode == POSITION)
	{
		f->zoom = f->width / 4.0;
		f->offset_x = 0;
		f->offset_y = 0;
		f->render.computing_row = 0;
		f->render.need_recompute = 1;
	}
	if (mode == COLOUR)
	{
		f->anim_phase = 0;
		f->colour_shift = 0;
		f->colour_scale = 0.035;
		f->render.need_recolour = 1;
	}
}
