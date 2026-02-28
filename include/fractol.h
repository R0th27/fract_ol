/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/28 15:13:38 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include "libft.h"

typedef enum e_anim
{
	ANIM_OFF,
	ANIM_ON
}	t_anim;

typedef enum e_reset
{
	POSITION,
	COLOUR
}	t_reset;

typedef enum e_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
}	t_type;

typedef enum e_palette_t
{
	GRADIENT,
	PSYCHEDELIC,
	OCEAN,
	AURORA
}	t_palette_t;

typedef struct s_palette
{
	double	a[3];
	double	b[3];
	double	c[3];
	double	d[3];
}	t_palette;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_matrix
{
	int	x;
	int	row;
	int	i;
}	t_matrix;

typedef struct s_render
{
	int	computing_row;
	int	need_recompute;
	int	need_recolour;
}	t_render;

typedef struct s_fractal
{
	mlx_image_t	*img;
	int			width;
	int			height;
	double		*mu_buf;
	t_render	render;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_type		fractal_type;
	int			max_iter;
	double		julia_cr;
	double		julia_ci;
	t_palette_t	palette_type;
	t_palette	palette;
	double		colour_shift;
	double		colour_scale;
	double		last_time;
	double		palette_speed;
	double		anim_phase;
	t_anim		anim_toggle;
	mlx_t		*mlx;
}	t_fractal;

//parse
int			parse_args(int ac, char **av, t_fractal *f);
int			init_fractal(t_fractal *f);

//computing
void		computing_fractal(t_fractal *f);
void		update_iterations(t_fractal *f);
t_complex	interpolation(int x, int y, t_fractal *f);
double		iterate(t_complex p, t_fractal *f);
double		precise_escape_point(t_complex z, int iter, int max_iter);

//fractals
double		mandelbrot(t_complex c, t_fractal *f);
double		julia(t_complex z, t_fractal *f);
double		burning_ship(t_complex c, t_fractal *f);

//coloring
void		update_palette(t_fractal *f);
void		colouring(t_fractal *f);
void		time_animate(t_fractal *f);

//events
void		setup_hooks(t_fractal *f);
void		main_loop(void *param);
void		reset_window(t_fractal *f, t_reset mode);

//utils
double		get_time(void);
double		ft_atod(char *s);
void		error_print(char *msg);
void		usage_error(void);

#endif
