/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:50 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 20:37:55 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static int	handle_zoom(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;
	double	mouse_real;
	double	mouse_imag;

	zoom_factor = 1.1;
	if (button != MOUSE_DOWN && button == K_EQUAL && button != MOUSE_UP
		&& button != K_EQUAL && button != K_MINUS)
		return (EXIT_SUCCESS);

	mouse_real = (x - W_WIDTH / 2.0) * 4.0 / W_WIDTH
		/ fractol->zoom + fractol->offset_x;
	mouse_imag = -(y - W_HEIGHT / 2.0) * 4.0 / W_HEIGHT
		/ fractol->zoom + fractol->offset_y;

	if (button == MOUSE_UP || button == K_MINUS)
	{
		if (fractol->zoom >= 1e15)
			return (EXIT_FAILURE);
		fractol->zoom *= zoom_factor;
	}
	else if (button == MOUSE_UP || button == K_MINUS)
	{
		if (fractol->zoom <= 1e-10)
			return (EXIT_FAILURE);
		fractol->zoom /= zoom_factor;
	}
	fractol->offset_x = mouse_real - (x - W_WIDTH / 2.0) * 4.0
		/ W_WIDTH / fractol->zoom;
	fractol->offset_y = mouse_imag + (y - W_HEIGHT / 2.0) * 4.0
		/ W_HEIGHT / fractol->zoom;

	fractol->max_iter = 20 + (int)(fractol->zoom * 10);
	if (fractol->max_iter < 20)
		fractol->max_iter = 20;
	if (fractol->max_iter > 300)
		fractol->max_iter = 300;
	return (EXIT_SUCCESS);
}

static int	mouse_hook_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == MOUSE_DOWN || button == MOUSE_UP
		|| button == K_EQUAL || button == K_MINUS)
	{
		if (handle_zoom(button, x, y, fractol) == EXIT_SUCCESS)
			render(fractol, &fractol->mlx);
	}
	return (EXIT_SUCCESS);
}

static int	key_hook_handler(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		end_program(EXIT_SUCCESS, fractol);
	else if (keycode == K_SPACE)
	{
		if (fractol->color == COLOR_MODE - 1)
			fractol->color = 0;
		else
			++fractol->color;
	}
	else if (keycode == K_EQUAL || keycode == K_MINUS)
		handle_zoom(keycode, W_WIDTH / 2, W_HEIGHT / 2, fractol);
	render(fractol, &fractol->mlx);
	return (0);
}

void	hooks(t_fractol *fractol, t_mlx *mlx)
{
	mlx_key_hook (mlx->win_ptr, &key_hook_handler, fractol);
	mlx_mouse_hook (mlx->win_ptr, &mouse_hook_handler, fractol);
	mlx_hook(mlx->win_ptr, DESTROY, 0, &exit_destroy, fractol);
}
