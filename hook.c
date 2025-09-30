/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:14:01 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 22:20:23 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_fractol *fractol, t_mlx *mlx)
{
	mlx_key_hook (mlx->win_ptr, &key_hook_handler, fractol);
	mlx_mouse_hook (mlx->win_ptr, &mouse_hook_handler, fractol);
	mlx_hook(mlx->win_ptr, DESTROY, 0, &exit_destroy, fractol);
}
