#include "fractol.h"

void	julia_set(t_fractol *fractol, t_coords coords)
{
	t_complex	z;
	int			i;

	z = pixel_to_complex(&fractol->view, coords);
	i = 0;
	while (i < fractol->max_iter)
	{
		add_complex(square_complex(z), fractol->c);
		if (mod2_complex(z) > ESCAPE_THRESHOLD_SQ)
		{
			put_pixel_divergence(fractol, coords, i, z);
			break ;
		}
		i++;
	}
	if (i == fractol->max_iter)
		put_pixel_convergence(fractol, coords);
}

void	mandelbrot_set(t_fractol *fractol, t_coords coords)
{
	
}

// static void	fractol(t_fractol *fractol)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < W_WIDTH)
// 	{
// 		y = 0;
// 		while (y < W_HEIGHT)
// 		{
// 			double radian_x = x * 0.2; // 波の細かさを調整
// 			double sin_y = sin(radian_x);
// 			int screen_y = (int)(sin_y * 100) + (W_HEIGHT / 2); // 振幅を100にし、中心をずらす

// 			pixel_put_to_image(&fractol->mlx.img, x, y, 0xffffff);
// 			if (x > W_WIDTH - 1 - 5 || y > W_HEIGHT - 1 - 5|| x < 5 || y < 5)
// 				pixel_put_to_image(&fractol->mlx.img, x, y, 0xff000);
// 			pixel_put_to_image(&fractol->mlx.img, x, screen_y, 0xff0000);
// 			y++;
// 		}
// 		x++;
// 	}
// }