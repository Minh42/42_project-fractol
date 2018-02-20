/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:30:47 by minh              #+#    #+#             */
/*   Updated: 2018/02/20 21:30:15 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     ft_checks_parameters(char **argv, t_env *e)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		e->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		e->fract = 1;
	else if (ft_strcmp(argv[1], "buddhabrot") == 0)
		e->fract = 2;
	else
	{
		ft_putendl("usage : ./fractol \"mandelbrot\", \"julia\", \"buddhabrot\"");
		return (0);
	}
	return (1);
}


int		main(int argc, char **argv)
{
    t_env e;

    if (argc != 2)
    {
    	ft_putendl("usage : ./fractol \"mandelbrot\", \"julia\", \"buddhabrot\"");
        exit(EXIT_SUCCESS);
    }
    else
        ft_checks_parameters(argv, &e);
    
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
    e.img.img_ptr = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.img.data = mlx_get_data_addr(e.img.img_ptr, &e.img.bpp, &e.img.sizeline, &e.img.endian);
    
    // ft_draw_julia(&e);
    ft_draw_mandelbrot(&e);
    mlx_loop(e.mlx);
    return (0);

}