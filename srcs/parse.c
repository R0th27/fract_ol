/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:07:08 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 17:52:52 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_graphic(t_fractal *f)
{
	f->mu_buf = malloc(sizeof(double) * f->width * f->height);
	if (!f->mu_buf)
		return (error_print("malloc failed\n"), 0);
	f->mlx = mlx_init(f->width, f->height, "fractol", true);
	if (!f->mlx)
		return (error_print("MLX INIT FAILED\n"), 0);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	if (!f->img)
		return (error_print("MLX IMG FAILED\n"), 0);
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (error_print("MLX IMG2WIN FAILED\n"), 0);
	return (1);
}

int	init_fractal(t_fractal *f)
{
	f->width = 1200;
	f->height = 800;
	f->zoom = f->width / 4.0;
	f->offset_x = -0.5;
	f->offset_y = 0;
	f->colour_shift = 0;
	f->colour_scale = 0.035;
	f->colour_mode = GRADIENT;
	f->render.need_recompute = 1;
	f->render.need_recolour = 0;
	f->render.computing_row = 0;
	f->last_time = get_time();
	f->palette_speed = 0.4;
	update_palette(f);
	return (init_graphic(f));
}

static int	parse_init(t_fractal *f, char **av, t_type type)
{
	if (type == MANDELBROT)
		f->type = MANDELBROT;
	else if (type == BURNING_SHIP)
		f->type = BURNING_SHIP;
	else if (type == JULIA)
	{
		f->type = JULIA;
		f->julia_cr = ft_atod(av[2]);
		f->julia_ci = ft_atod(av[3]);
	}
	return (1);
}

int	parse_args(int ac, char **av, t_fractal *f)
{
	if (ac < 2 || ac > 4)
		return (usage_error(), 0);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		return (parse_init(f, av, MANDELBROT));
	else if (ac == 2 && !ft_strncmp(av[1], "burning_ship", 13))
		return (parse_init(f, av, BURNING_SHIP));
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
		return (parse_init(f, av, JULIA));
	return (usage_error(), 0);
}
