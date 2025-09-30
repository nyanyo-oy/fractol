/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:40 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 15:15:41 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return (c);
}

double	mod2_complex(t_complex a)
{
	return (a.real * a.real + a.imag * a.imag);
}

t_complex	square_complex(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.imag * a.imag;
	c.imag = 2 * a.real * a.imag;
	return (c);
}
