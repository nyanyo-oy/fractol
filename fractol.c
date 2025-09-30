/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:43 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 19:09:30 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	core_fractol(t_fractol *fractol)
{
	t_coords	coords;
	int			x;
	int			y;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
		{
			coords.x = x;
			coords.y = y;
			fractol->set_handler(fractol, coords);
			y++;
		}
		x++;
	}
}

void	render(t_fractol *fractol, t_mlx *mlx)
{
	void	*img_old_ptr;

	img_old_ptr = mlx->img.img_ptr;
	put_new_image(fractol, mlx, &mlx->img);
	core_fractol(fractol);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	if (img_old_ptr)
		mlx_destroy_image(mlx->mlx_ptr, img_old_ptr);
}
