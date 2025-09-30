/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:50 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 17:24:35 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_zoom(int button, int x, int y, t_fractol *fractol)
{
	int		sign;
	double	delta_x;
	double	delta_y;

	sign = 0;
	if (button == MOUSE_DOWN || button == K_EQUAL)
		sign = 1;
	else if (button == MOUSE_UP || button == K_MINUS)
		sign = -1;
	delta_x = (fractol->view.max_x - fractol->view.min_x) * 0.1;
	delta_y = (fractol->view.max_y - fractol->view.min_y) * 0.1;
	if (((delta_x < 1e-15 || delta_y < 1e-15) && sign == 1)
		|| ((delta_x > 2e80 || delta_y > 2e80) && sign == -1))
		return (EXIT_FAILURE);
	fractol->view.max_x = fractol->view.max_x
		- (delta_x * ((double)1 - (double)x / (W_WIDTH - 1))) * sign;
	fractol->view.min_x = fractol->view.min_x
		+ (delta_x * ((double)x / (W_WIDTH - 1))) * sign;
	fractol->view.max_y = fractol->view.min_y
		- (delta_y * ((double)y / (W_HEIGHT - 1))) * sign;
	fractol->view.max_y = fractol->view.min_y
		+ (delta_y * ((double)1 - (double)y / (W_HEIGHT - 1))) * sign;
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
	mlx_key_hook (mlx->win_ptr, &key_hook_handler, mlx);
	mlx_mouse_hook (mlx->win_ptr, &mouse_hook_handler, fractol);
	mlx_hook(mlx->win_ptr, DESTROY, 0, &exit_destroy, fractol);
}
