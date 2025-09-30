/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:13:00 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 20:34:43 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel_to_complex_zoom(t_fractol *fractol, t_coords coords)
{
	t_complex	c;

	c.real = (coords.x - W_WIDTH / 2.0) * 4.0
		/ W_WIDTH / fractol->zoom + fractol->offset_x;
	c.imag = -(coords.y - W_HEIGHT / 2.0) * 4.0
		/ W_WIDTH / fractol->zoom + fractol->offset_y;
	return (c);
}

//t_complex	pixel_to_complex(t_view *view, t_coords coords)
//{
//	t_complex	c;
//	double		x_range;
//	double		y_range;

//	x_range = view->max_x - view->min_x;
//	y_range = view->max_y - view->min_y;

//	c.real = view->min_x + (double)coords.x / (W_WIDTH - 1) * x_range;
//	c.imag = view->min_y + (double)coords.y / (W_HEIGHT - 1) * y_range;
//	return (c);
//}
