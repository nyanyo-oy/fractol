#include "fractol.h"

void	put_new_window(t_fractol *fractol, t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "fractol");
	if (!fractol->mlx.win_ptr)
		end_program(EXIT_FAILURE, fractol);
}

void	put_new_image(t_fractol *fractol, t_mlx *mlx, t_img *img)
{
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!mlx->img.img_ptr)
		end_program(EXIT_FAILURE, fractol);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, 
		&img->size_line, &img->endian);
	if (!img->addr)
		end_program(EXIT_FAILURE, fractol);
}

static int	swap_endian(int color)
{
	return(((color & 0xFF000000) >> 24) | ((color & 0x00FF0000) >> 8) | 
		((color & 0x0000FF00) << 8) | ((color & 0x000000FF) << 24));
}

void	put_pixel(t_img *img, t_coords coords, int color)
{
	char	*dst;
	
	if (img->endian == IS_BIG_ENDIAN)
		color = swap_endian(color);
	dst = img->addr + (coords.x * (img->bits_per_pixel / 8) + coords.y * img->size_line);
	*(int *)dst = color;
}
