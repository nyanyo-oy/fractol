#include "fractol.h"

void fractol_init(t_fractol *fractol)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->max_iter = 20;
	fractol->c.real = -1;
	fractol->c.imag = 0;
}

void	graphics_init(t_fractol *fractol, t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		end_program(EXIT_FAILURE, fractol);
}

void	sets_init(t_set *sets)
{
	sets[0].name = SET_01;
	sets[0].render_func = &julia_set;
	sets[1].name = SET_02;
	sets[1].render_func = &mandelbrot_set;
	sets[SET_COUNT].name = NULL;
	sets[SET_COUNT].render_func = NULL;
}


