/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:42:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 19:00:45 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_fractal(t_fractal *f)
{
	f->zoom = WIDTH / 4.0;
	f->offset_x = 0;
	f->offset_y = 0;
	f->colour_shift = 0;
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!f->mlx)
		return (0);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		return (0);
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (0);
	return (1);
}
