/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:29 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 06:30:51 by htoe             ###   ########.fr       */
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
	computing_fractal(&f);
	setup_hooks(&f);
	coloring(&f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	free(f.mu_buf);
	return (EXIT_SUCCESS);
}
