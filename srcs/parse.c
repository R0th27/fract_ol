/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:07:08 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 18:08:27 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	color_mode_init(t_fractal *f, char *mode)
{
	if (!ft_strncmp(mode, "cyclic", 7))
		f->colour_mode = CYCLIC;
	else
		f->colour_mode = GRADIENT;
}

int	parse_args(int ac, char **av, t_fractal *f)
{
	if (ac < 2 || ac > 5)
		return (usage_error(), 0);
	color_mode_init(f, av[ac - 1]);
	if (ac >= 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		return (parse_init(f, av, MANDELBROT));
	else if (ac >= 2 && !ft_strncmp(av[1], "burning_ship", 13))
		return (parse_init(f, av, BURNING_SHIP));
	else if (ac >= 4 && !ft_strncmp(av[1], "julia", 6))
		return (parse_init(f, av, JULIA));
	return (usage_error(), 0);
}
