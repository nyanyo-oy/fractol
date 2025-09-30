/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:37 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 15:15:09 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_convergence(t_fractol *fractol, t_coords coords)
{
	const int	colors[COLOR_MODE] = {0, 1, 10, 316};

	put_pixel(&fractol->mlx.img, coords, 0xFF000000 + colors[fractol->color]
		* (int)fabs((double)(coords.x + coords.y)));
}

void	put_pixel_divergence(t_fractol *fractol, t_coords coords,
		int iter, t_complex z)
{
	double	smooth;
	int		color;

	smooth = iter + 2 + (log(log(mod2_complex(z))) / log(2));
	color = DIVERGENCE_BASE_COLOR * smooth / fractol->max_iter;
	put_pixel(&fractol->mlx.img, coords, color);
}
