/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:30:47 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 15:01:23 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     ft_checks_parameters(char **argv, t_env *e)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		e->fract = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		e->fract = 1;
	else if (ft_strcmp(argv[1], "burnship") == 0)
		e->fract = 2;
	else if (ft_strcmp(argv[1], "buddhabrot") == 0)
		e->fract = 3;
	else
	{
		ft_putendl("usage : ./fractol \"mandelbrot\", \"julia\", \"buddhabrot\"");
		return (0);
	}
	return (1);
}

void		ft_create_image(t_env *e)
{
	e->img.img_ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &e->img.bpp,
	&e->img.sizeline, &e->img.endian);
	if (e->fract == 0)
		ft_draw_mandelbrot(e);
	if (e->fract == 1)
		ft_draw_julia(e);
	if (e->fract == 2)
		ft_draw_burnship(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void	ft_fill_pixel(t_env *e, int x, int y, int rgb_color)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		e->img.data[y * WIN_WIDTH + x] = rgb_color;
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
    ft_create_image(&e);
    mlx_hook(e.win, 2, 0, key_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}