/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:12:46 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/30 22:29:33 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define W_WIDTH 860
# define W_HEIGHT 430

# define SUCCESS 0
# define FAILURE 1

# define SET_01 "julia"
# define SET_02 "mandelbrot"

# define IS_LITTLE_ENDIAN 0
# define IS_BIG_ENDIAN 1

# define ESCAPE_THRESHOLD_SQ 4.0

# define DIVERGENCE_BASE_COLOR 13283165

# define DESTROY 17

# define K_ESC 0xff1b
# define K_EQUAL 0x3d
# define K_MINUS 0x2d
# define K_SPACE 0x20
# define MOUSE_DOWN 4
# define MOUSE_UP 5

struct						s_fractol;
struct						s_coords;
typedef void				(*t_render_func)(struct s_fractol *,
								struct s_coords);

typedef struct s_set
{
	const char				*name;
	t_render_func			render_func;
}							t_set;

typedef struct s_complex
{
	double					real;
	double					imag;
}							t_complex;

typedef struct s_mouse
{
	int						x;
	int						y;
}							t_mouse;

typedef struct s_img
{
	void					*img_ptr;
	char					*addr;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
}							t_img;

typedef struct s_mlx
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_img					img;
}							t_mlx;

typedef struct s_view
{
	double					min_x;
	double					min_y;
	double					max_x;
	double					max_y;
}							t_view;

struct						s_coords
{
	int						x;
	int						y;
};

struct						s_fractol
{
	t_mlx					mlx;
	t_view					view;
	t_complex				c;
	unsigned int			max_iter;
	t_render_func			set_handler;
	int						color;

	double					zoom;
	double					offset_x;
	double					offset_y;
};

typedef struct s_fractol	t_fractol;
typedef struct s_coords		t_coords;

void						put_pixel_convergence(t_fractol *fractol,
								t_coords coords);
void						put_pixel_divergence(t_fractol *fractol,
								t_coords coords, int iter, t_complex z);

t_complex					add_complex(t_complex a, t_complex b);
double						mod2_complex(t_complex a);
t_complex					square_complex(t_complex a);

void						render(t_fractol *fractol, t_mlx *mlx);

void						hooks(t_fractol *fractol, t_mlx *mlx);

void						fractol_init(t_fractol *fractol);
void						graphics_init(t_fractol *fractol, t_mlx *mlx);

t_complex					pixel_to_complex_zoom(t_fractol *fractol,
								t_coords coords);

void						put_new_window(t_fractol *fractol, t_mlx *mlx);
void						put_new_image(t_fractol *fractol, t_mlx *mlx,
								t_img *img);
void						put_pixel(t_img *img, t_coords coords, int color);

void						parse(t_fractol *fractol, int arc, char **arv);

void						julia_set(t_fractol *fractol, t_coords coords);
void						mandelbrot_set(t_fractol *fractol, t_coords coords);

void						end_program(int exit_status, t_fractol *fractol);
void						end_program_with_help(int exit_status,
								t_fractol *fractol);
int							exit_destroy(t_fractol *fractol);
bool						is_number_str(char *str);

int							key_hook_handler(int keycode, t_fractol *fractol);
int							mouse_hook_handler(int button, int x, int y,
								t_fractol *fractol);

#endif
