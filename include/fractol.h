/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:12:30 by htoe              #+#    #+#             */
/*   Updated: 2026/02/23 18:11:05 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef enum e_type
{
	MANDELBROT,
	JULIA
}	t_type;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_type		type;
	double		offset_x;
	double		offset_y;
	double		zoom;
	double		julia_cr;
	double		julia_ci;
	int			max_iter;
}	t_fractal;

//error
void	error_print(char *msg);
void	usage_error(void);

#endif
