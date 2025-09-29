#include "fractol.h"

static void set_router(t_fractol *fractol, char *parameter)
{
	int	i;

	i = 0;
	while (fractol->sets[i].name)
	{
		if(ft_strcmp(parameter, fractol->sets[i].name) == SUCCESS)
		{
			fractol->set_handler = fractol->sets[i].render_func;
			break;
		}
		i++;
	}
	if (fractol->sets[i].name == NULL)
		end_program_with_help(EXIT_FAILURE, fractol);
}

static void parse_options(t_fractol *fractol, int arc, char **arv)
{
	if (fractol->set_handler == &julia_set)
	{
		if (arc == 4)
		{
			fractol->c.real = ft_atof_lite(arv[2]);
			fractol->c.imag = ft_atof_lite(arv[3]);
			if (fractol->c.real < -1000.0 || fractol->c.imag > 1000.0 || \
				fractol->c.imag < -1000.0 || fractol->c.imag > 1000.0)
			{
				end_program_with_help(EXIT_FAILURE, fractol);
			}
		}
	}
	else if (arc > 3)
	{
		end_program_with_help(EXIT_FAILURE, fractol);
	}
}

void	parse(t_fractol *fractol, int arc, char **arv)
{
	if (arc != 2 && arc != 4)
		end_program_with_help(EXIT_FAILURE, fractol);
	if (arc == 4)
	{
		if (is_number_str(arv[2]) == false && \
				is_number_str(arv[3]) == false)
		{
			end_program_with_help(EXIT_FAILURE, fractol);
		}
	}
	set_router(fractol, arv[1]);
	parse_options(fractol, arc, arv);
}