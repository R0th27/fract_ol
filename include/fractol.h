/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 18:09:34 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

typedef enum e_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_type;

typedef enum e_color
{
	GRADIENT,
	CYCLIC
}	t_color;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_type		type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		julia_cr;
	double		julia_ci;
	int			max_iter;
	t_color		colour_mode;
	double		colour_shift;
}	t_fractal;

//parse
int		parse_args(int ac, char **av, t_fractal *f);

//utils
double	ft_atod(char *s);

//error
void	error_print(char *msg);
void	usage_error(void);

#endif
