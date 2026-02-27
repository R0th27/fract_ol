/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:24:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 16:13:12 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	input_loop(void *param)
{
	t_fractal	*f;
	double		shift;

	f = param;
	shift = 20.0 / f->zoom;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		return (f->offset_x -= shift, (void)(f->render.need_recompute = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		return (f->offset_x += shift, (void)(f->render.need_recompute = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		return (f->offset_y -= shift, (void)(f->render.need_recompute = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		return (f->offset_y += shift, (void)(f->render.need_recompute = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_A))
		return (f->colour_shift += 0.02, (void)(f->render.need_recolour = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		return (f->colour_shift -= 0.02, (void)(f->render.need_recolour = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_W))
		return (f->colour_scale *= 1.02, (void)(f->render.need_recolour = 1));
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
		return (f->colour_scale *= 0.98, (void)(f->render.need_recolour = 1));
}

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
	f->offset_x = mouse.r - (mx - f->width / 2.0) / f->zoom;
	f->offset_y = mouse.i - (my - f->height / 2.0) / f->zoom;
	f->render.need_recompute = 1;
}

static void	key_press(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_C)
	{
		if (f->colour_mode == PSYCHEDELIC)
			f->colour_mode = GRADIENT;
		else
			f->colour_mode++;
	}
	update_palette(f);
	f->render.need_recolour = 1;
}

static void	render_hook(void *param)
{
	t_fractal	*f;

	f = param;
	if (f->render.need_recompute)
		computing_fractal(f);
	if (f->render.need_recolour)
		colouring(f);
}

void	setup_hooks(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, scroll_hook, f);
	mlx_key_hook(f->mlx, key_press, f);
	mlx_loop_hook(f->mlx, input_loop, f);
	mlx_loop_hook(f->mlx, render_hook, f);
}
