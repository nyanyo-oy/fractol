#include "fractol.h"

int	main(int arc, char **arv)
{
	t_fractol	fractol;
	
	sets_init(fractol.sets);
	fractol_init(&fractol);
	parse(&fractol, arc, arv);
	graphics_init(&fractol, &fractol.mlx);
	render(&fractol, &fractol.mlx);
	
	// mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, 250, 250, 0xFFFFFFF);
	// mlx_key_hook (mlx.win_ptr, ));

	init_hooks(&fractol);
	mlx_loop(fractol.mlx.mlx_ptr);
}
