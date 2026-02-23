/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:19:01 by htoe              #+#    #+#             */
/*   Updated: 2026/02/23 18:02:59 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage_error(void)
{
	error_print("Usage:\n"
			"./fractol mandelbrot\n"
			"./fractol julia <real> <imag>\n");
}

void	error_print(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
}
