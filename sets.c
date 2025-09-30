/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:13:13 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 20:38:53 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(t_fractol *fractol, t_coords coords)
{
	t_complex		z;
	unsigned int	i;

	z = pixel_to_complex_zoom(fractol, coords);
	i = 0;
	while (i < fractol->max_iter)
	{
		z = add_complex(square_complex(z), fractol->c);
		if (mod2_complex(z) > ESCAPE_THRESHOLD_SQ)
		{
			put_pixel_divergence(fractol, coords, i, z);
			break ;
		}
		i++;
	}
	if (i == fractol->max_iter)
		put_pixel_convergence(fractol, coords);
}

void	mandelbrot_set(t_fractol *fractol, t_coords coords)
{
	t_complex		z;
	unsigned int	i;

	z.real = 0;
	z.imag = 0;
	fractol->c = pixel_to_complex_zoom(fractol, coords);
	i = 0;
	while (i < fractol->max_iter)
	{
		z = add_complex(square_complex(z), fractol->c);
		if (mod2_complex(z) > ESCAPE_THRESHOLD_SQ)
		{
			put_pixel_divergence(fractol, coords, i, z);
			break ;
		}
		i++;
	}
	if (i == fractol->max_iter)
		put_pixel_convergence(fractol, coords);
}
