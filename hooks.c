#include "fractol.h"

int	key_hook_handler(int keycode, void *param)
{
	t_mlx *mlx = (t_mlx *)param;
	if (keycode == 0xff1b)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->img.img_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		free(mlx->mlx_ptr);
		exit(0);
	}
	else if (keycode == )
	return (0);
}

int	mouse_hook_handler()
{
	
}

void	init_hooks(t_fractol *fractol)
{
	mlx_key_hook (fractol->mlx.win_ptr, key_hook_handler, &fractol->mlx);
	mlx_mouse_hook (fractol->mlx.win_ptr, &mouse_hook_handler, void *param);
	mlx_
}
