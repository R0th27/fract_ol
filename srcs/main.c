/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:29 by htoe              #+#    #+#             */
/*   Updated: 2026/02/23 18:17:03 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(char *s)
{
	double	result;
	double	sign;
	double	frac;

	result = 0;
	sign = 1;
	frac = 0.1;
	if (*s == '+' || *s == '-')
		sign = 44 - *s++;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			result += (*s++ - '0') * frac;
			frac *= 0.1;
		}
	}
	return (result * sign);		
}

int	parse_args(int ac, char **av, t_fractal *f)
{
	if (ac < 2)
		return (usage_error(), 0);
	if (!ft_strncmp(av[1], "mandelbrot", 11) && ac == 2)
		f->type = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
	{
		f->type = JULIA;
		f->julia_cr = ft_atod(av[2]);
		f->julia_ci = ft_atod(av[2]);
	}
	else
		return (usage_error(), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (!parse_args(argc, argv, &f))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}