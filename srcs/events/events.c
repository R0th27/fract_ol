/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:23:28 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 16:53:16 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render(t_fractal *f)
{
	if (f->render.need_recompute)
		computing_fractal(f);
	if (f->render.need_recolour)
		colouring(f);
}

static void	colour_control(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_A))
	{
		f->colour_shift += 0.02;
		f->render.need_recolour = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
	{
		f->colour_shift -= 0.02;
		f->render.need_recolour = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_W))
	{
		f->colour_scale *= 1.02;
		f->render.need_recolour = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
	{
		f->colour_scale *= 0.98;
		f->render.need_recolour = 1;
	}
}

static void	movement_detect(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->offset_x -= 10.0 / f->zoom;
		f->render.computing_row = 0;
		f->render.need_recompute = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->offset_x += 10.0 / f->zoom;
		f->render.computing_row = 0;
		f->render.need_recompute = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->offset_y -= 10.0 / f->zoom;
		f->render.computing_row = 0;
		f->render.need_recompute = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->offset_y += 10.0 / f->zoom;
		f->render.computing_row = 0;
		f->render.need_recompute = 1;
	}
}

static void	close_detect(t_fractal *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
}

void	main_loop(void *param)
{
	t_fractal	*f;

	f = param;
	close_detect(f);
	movement_detect(f);
	colour_control(f);
	render(f);
}
