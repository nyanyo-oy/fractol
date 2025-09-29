#include "fractol.h"

int	main(int arc, char **arv)
{
	t_fractol	fractol;
	
	sets_init(fractol.sets);
	fractol_init(&fractol);
	parse(&fractol, arc, arv);
	graphics_init(&fractol, &fractol.mlx);
	render(&fractol, &fractol.mlx);
	
	// mlx_key_hook (mlx.win_ptr, ));

	hooks(&fractol, &fractol.mlx);
	mlx_loop(fractol.mlx.mlx_ptr);
}
