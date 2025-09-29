#include "fractol.h"

static int	mouse_hook_handler(int keycode, t_fractol *fractol)
{
	
}

static int	key_hook_handler(int keycode, t_fractol *fractol)
{
	if (keycode == 0xff1b)
		end_program(EXIT_SUCCESS, fractol);
	else if (keycode == )
	return (0);
}

void	init_hooks(t_fractol *fractol, t_mlx *mlx)
{
	mlx_key_hook (mlx->win_ptr, &key_hook_handler, mlx);
	mlx_mouse_hook (mlx->win_ptr, &mouse_hook_handler, fractol);
	mlx_hook(mlx->win_ptr, DESTROY, 0, &exit_destroy, fractol)
}
