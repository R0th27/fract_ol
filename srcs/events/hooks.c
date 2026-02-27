/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:24:59 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 18:04:12 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_fractal	*f;

	f = param;
	if (width <= 0 || height <= 0)
		return ;
	f->width = width;
	f->height = height;
	mlx_resize_image(f->img, width, height);
	free(f->mu_buf);
	f->mu_buf = (double *)malloc(sizeof(double) * width * height);
	f->render.computing_row = 0;
	f->render.need_recompute = 1;
}

static void	close_hook(void *param)
{
	t_fractal	*f;

	f = param;
	free(f->mu_buf);
	exit(EXIT_SUCCESS);
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
	f->render.computing_row = 0;
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
		if (f->colour_mode == TIME)
			f->colour_mode = GRADIENT;
		else
			f->colour_mode++;
	}
	update_palette(f);
	f->render.need_recolour = 1;
}

void	setup_hooks(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, scroll_hook, f);
	mlx_close_hook(f->mlx, close_hook, f);
	mlx_key_hook(f->mlx, key_press, f);
	mlx_resize_hook(f->mlx, resize_hook, f);
	mlx_loop_hook(f->mlx, main_loop, f);
}
