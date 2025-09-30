/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:53 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 19:52:04 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->max_iter = 20;
	fractol->c.real = -1;
	fractol->c.imag = 0;

	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
}

void	graphics_init(t_fractol *fractol, t_mlx *mlx)
{
	int	lowest;

	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		end_program(EXIT_FAILURE, fractol);
	put_new_window(fractol, mlx);
	if (W_WIDTH >= W_HEIGHT)
		lowest = W_HEIGHT;
	else
		lowest = W_WIDTH;
	fractol->view.max_x = 2.0 * W_WIDTH / lowest;
	fractol->view.min_x = -2.0 * W_WIDTH / lowest;
	fractol->view.max_y = 2.0 * W_HEIGHT / lowest;
	fractol->view.min_y = -2.0 * W_HEIGHT / lowest;
}
