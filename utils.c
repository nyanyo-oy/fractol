/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:13:16 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 21:41:07 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	end_program(int exit_status, t_fractol *fractol)
{
	if (fractol->mlx.img.img_ptr)
		mlx_destroy_image(fractol->mlx.mlx_ptr, fractol->mlx.img.img_ptr);
	if (fractol->mlx.win_ptr)
		mlx_destroy_window(fractol->mlx.mlx_ptr, fractol->mlx.win_ptr);
	if (fractol->mlx.mlx_ptr)
	{
		mlx_destroy_display(fractol->mlx.mlx_ptr);
		free (fractol->mlx.mlx_ptr);
	}
	exit (exit_status);
}

void	end_program_with_help(int exit_status, t_fractol *fractol)
{
	ft_printf("./fractol julia (r [-1000.0, 1000.0] \
			 i [-1000.0, 1000.0])\n");
	ft_printf("./fractol mandelbrot\n");
	end_program(exit_status, fractol);
}

int	exit_destroy(t_fractol *fractol)
{
	end_program(EXIT_SUCCESS, fractol);
	return (EXIT_SUCCESS);
}

bool	is_number_str(char *str)
{
	int	i;
	int	point;

	i = 0;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	if (str[i] == '.')
		return (false);
	point = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (point == 0)
				point = 1;
			else
				return (false);
		}
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
