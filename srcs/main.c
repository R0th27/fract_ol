/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:29 by htoe              #+#    #+#             */
/*   Updated: 2026/02/27 12:03:13 by htoe             ###   ########.fr       */
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
	mlx_terminate(f.mlx);
	free(f.mu_buf);
	return (EXIT_SUCCESS);
}
