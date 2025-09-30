/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:56 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 16:02:12 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int arc, char **arv)
{
	t_fractol	fractol;

	fractol_init(&fractol);
	parse(&fractol, arc, arv);
	graphics_init(&fractol, &fractol.mlx);
	render(&fractol, &fractol.mlx);
	hooks(&fractol, &fractol.mlx);
	mlx_loop(fractol.mlx.mlx_ptr);
}
