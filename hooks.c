#include "fractol.h"

static int	handle_zoom(int button, int x, int y, t_fractol *fractol)
{
	int		sign;
	double	zoom_x;
	double	zoom_y;
	
	sign = 0;
	if (button == MOUSE_DOWN || button == XK_equal)
		sign = 1;
	else if (button == MOUSE_UP || button == XK_minus)
		sign = -1;
	zoom_x = (fractol->view.max_x - fractol->view.min_x) * 0.1;
	zoom_y = (fractol->view.max_y - fractol->view.min_y) * 0.1;
	if (((zoom_x < 0.000000000000001 || zoom_y < 0.000000000000001))
		
	

}
static int	mouse_hook_handler(int button, int x, int y, t_fractol *fractol)
{
	if (button == MOUSE_DOWN || button == MOUSE_UP || 
		button == XK_equal || button == XK_minus)
	{
		if (handle_zoom(button, x, y, fractol) == EXIT_SUCCESS)
			render(fractol, &fractol->mlx);
	}
	return (EXIT_SUCCESS);
}

static int	key_hook_handler(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		end_program(EXIT_SUCCESS, fractol);
	else if (keycode == XK_space)
	{
		if(fractol->color == COLOR_MODE - 1)
			fractol->color = 0;
		else
			++fractol->color;
	}
	else if (keycode == XK_equal || keycode == XK_minus)
		handle_zoom(keycode, W_WIDTH / 2, W_HEIGHT / 2, fractol);
		
	return (0);
}

void	init_hooks(t_fractol *fractol, t_mlx *mlx)
{
	mlx_key_hook (mlx->win_ptr, &key_hook_handler, mlx);
	mlx_mouse_hook (mlx->win_ptr, &mouse_hook_handler, fractol);
	mlx_hook(mlx->win_ptr, DESTROY, 0, &exit_destroy, fractol);
}
