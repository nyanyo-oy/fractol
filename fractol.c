#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define W_HEIGHT 500
#define W_WIDTH 500

typedef struct s_img
{
	void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_vars;


int	key_hook_handler(int keycode, void *param)
{
	t_vars *vars = (t_vars *)param;
	if (keycode == 0xff1b)
	{
		mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

void	pixel_put_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (x * (img->bits_per_pixel / 8) + y * img->size_line);
	*(unsigned int *)dst = color;
}


int	main(void)
{
	t_vars 	vars;
	int	x;
	int	y;

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (1);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, W_HEIGHT, W_WIDTH, "abcd");
	if (!vars.win_ptr)
		return (1);

	// img_
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, W_HEIGHT, W_WIDTH);
	vars.img.addr = mlx_get_data_addr(vars.img.img_ptr,
		&vars.img.bits_per_pixel, &vars.img.size_line, &vars.img.endian);

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			double radian_x = x * 0.2; // 波の細かさを調整
			double sin_y = sin(radian_x);
			int screen_y = (int)(sin_y * 100) + (W_HEIGHT / 2); // 振幅を100にし、中心をずらす
	
			pixel_put_to_image(&vars.img, x, y, 0xffffff);
			if (x > W_WIDTH - 1 - 5 || y > W_HEIGHT - 1 - 5|| x < 5 || y < 5)
				pixel_put_to_image(&vars.img, x, y, 0xff000);
			pixel_put_to_image(&vars.img, x, screen_y, 0xff0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img.img_ptr, 0, 0);

	
	// mlx_pixel_put(vars.mlx_ptr, vars.win_ptr, 250, 250, 0xFFFFFFF);

	mlx_key_hook (vars.win_ptr, key_hook_handler, &vars);
	// mlx_key_hook (vars.win_ptr, ));
	mlx_loop(vars.mlx_ptr);
}
