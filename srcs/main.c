/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:29 by htoe              #+#    #+#             */
/*   Updated: 2026/02/28 12:08:40 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (!parse_args(argc, argv, &f))
		return (EXIT_FAILURE);
	if (!init_fractal(&f))
		return (EXIT_FAILURE);
	setup_hooks(&f);
	mlx_loop(f.mlx);
	free(f.mu_buf);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}

//TESTING FOR MLX LIBRARY GPU MALLOC ERROR
//int	main(void)
//{
//	mlx_t		*mlx;
//	mlx_image_t	*img;

//	mlx = mlx_init(1200, 800, "fractol", true);
//	img = mlx_new_image(mlx, 1200, 800);
//	mlx_image_to_window(mlx, img, 0, 0);
//	mlx_close_window(mlx);
//	mlx_terminate(mlx);
//	return (0);
//}