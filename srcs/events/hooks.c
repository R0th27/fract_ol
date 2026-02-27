/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:24:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 06:54:47 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	t_complex	mouse;
	double		zoom_factor;
	int32_t		mx;
	int32_t		my;

	(void)xdelta;
	f = param;
	mlx_get_mouse_pos(f->mlx, &mx, &my);
	if (ydelta > 0)
		zoom_factor = 1.2;
	else
		zoom_factor = 0.8;
	mouse = interpolation(mx, my, f);
	f->zoom *= zoom_factor;
	f->offset_x = mouse.r - (mx - WIDTH / 2.0) / f->zoom;
	f->offset_y = mouse.i - (my - HEIGHT / 2.0) / f->zoom;
}

static void	key_hook(void *param)
{
	t_fractal	*f;
	double		shift;

	f = param;
	shift = 20.0 / f->zoom;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->offset_x -= shift;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->offset_x += shift;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->offset_y -= shift;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->offset_y += shift;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Q))
		f->colour_shift += 0.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_E))
		f->colour_shift -= 0.05;
}

static void	key_press(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_C)
	{
		if (f->colour_mode == GRADIENT)
			f->colour_mode = PSYCHEDELIC;
		else
			f->colour_mode = GRADIENT;
	}
	update_palette(f);
	coloring(f);
}

void	setup_hooks(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, scroll_hook, f);
	mlx_loop_hook(f->mlx, key_hook, f);
	mlx_key_hook(f->mlx, key_press, f);
}
