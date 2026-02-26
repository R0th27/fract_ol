/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 23:26:11 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1200
# define HEIGHT 800

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
	PSYCHEDELIC
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
int			parse_args(int ac, char **av, t_fractal *f);
int			init_fractal(t_fractal *f);

//rendering
void		render(t_fractal *f);
void		update_iterations(t_fractal *f);
t_complex	interpolation(int x, int y, t_fractal *f);
double		iterate(t_complex p, t_fractal *f);

//fractals
double		mandelbrot(t_complex c, t_fractal *f);
double		julia(t_complex z, t_fractal *f);
double		burning_ship(t_complex c, t_fractal *f);

//coloring
double		escape_speed(t_complex z, int iter, int max_iter);
int32_t		get_color(double mu, t_fractal *f);

//events
void		setup_hooks(t_fractal *f);

//utils
double		ft_atod(char *s);
void		error_print(char *msg);
void		usage_error(void);

#endif
