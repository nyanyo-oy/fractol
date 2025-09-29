#include "fractol.h"

t_complex	pixel_to_complex(t_view *view, t_coords coords)
{
	t_complex	c;
	double		x_range;
	double		y_range;
	
	x_range = view->max_x - view->min_x;
	y_range = view->max_y - view->min_y;
	c.real = view->min_x + (double)coords.x / (W_WIDTH - 1) * x_range;
	c.imag = view->min_y + (double)coords.y / (W_HEIGHT - 1) * y_range;
	return (c);
}
