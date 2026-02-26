/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:19:01 by htoe              #+#    #+#             */
/*   Updated: 2026/02/26 18:10:07 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage_error(void)
{
	error_print("Usage: fractal_set (real) (imag) (color_mode)\n"
		"./fractol mandelbrot\n"
		"./fractol julia <real> <imag>\n"
		"./fractol burning_ship\n"
		"color_mode: Default for GRADIENT; 1 for CYCLIC\n");
}

void	error_print(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}
