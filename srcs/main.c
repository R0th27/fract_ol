/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:29 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 20:24:31 by htoe             ###   ########.fr       */
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
	render(&f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
