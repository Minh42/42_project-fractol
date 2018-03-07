/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:30:47 by minh              #+#    #+#             */
/*   Updated: 2018/03/07 10:53:23 by mpham            ###   ########.fr       */
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
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		e->fract = 3;
	else if (ft_strcmp(argv[1], "barnsley") == 0)
		e->fract = 4;
	else
	{
		ft_putendl("usage : ./fractol \"mandelbrot\", \"julia\", \"burnship\", \"tricorn\", \"barnsley\"");
		return (0);
	}
	return (1);
}

void    init_fractal(t_env *e)
{
    e->movex = 0; 
    e->movey = 0;
    e->max_iter = 300;
    e->re_max = 2.27;
    e->re_min = -2.7;
    e->im_max = 1.4;
    e->im_min = -1.4;
}

void		ft_create_image(t_env *e)
{
	e->img.img_ptr = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->img.data = (int *)mlx_get_data_addr(e->img.img_ptr, &e->img.bpp,
	&e->img.sizeline, &e->img.endian);
	init_fractal(e);
	if (e->fract == 0)
		ft_draw_mandelbrot(e);
	if (e->fract == 1)
		ft_draw_julia(e);				
	if (e->fract == 2)
		ft_draw_burnship(e);
	if (e->fract == 3)
		ft_draw_tricorn(e);
	if (e->fract == 4)
		ft_draw_barnsley(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

void	ft_fill_pixel(t_env *e, int x, int y, int rgb_color)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		e->img.data[y * WIN_WIDTH + x] = rgb_color;
}

// void	ft_print_dashboard(t_env *e)
// {
// 		mlx_string_put(e->mlx, e->win, 10, 22, 0x00FFFFFF, "FOV :");
// 	mlx_string_put(e->mlx, e->win, 70, 22, 0x00FFFFFF, ft_itoa(e->cam->fov));
	
// 	mlx_string_put(e->mlx, e->win, 25, 15, 0x00FFFFFF, "Quit = ESC");
// 	mlx_string_put(e->mlx, e->win, 25, 35, 0x00FFFFFF, "Move = < > ^ v");
// 	mlx_string_put(e->mlx, e->win, 25, 55, 0x00FFFFFF, "Zoom = + OR -");
// 	mlx_string_put(e->mlx, e->win, 25, 75, 0x00FFFFFF,
// 	"Alt = Page up OR Page down");
// 	mlx_string_put(e->mlx, e->win, 25, 95, 0x00FFFFFF, "Rx = W OR S");
// 	mlx_string_put(e->mlx, e->win, 25, 115, 0x00FFFFFF, "Ry = A OR D");
// 	mlx_string_put(e->mlx, e->win, 25, 135, 0x00FFFFFF, "Rz = Q OR E");
// 	mlx_string_put(e->mlx, e->win, 25, 155, 0x00FFFFFF, "Reset = SPACE");
// }

void	ft_redraw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (e->fract == 0)
		ft_draw_mandelbrot(e);
	if (e->fract == 1)
		ft_draw_julia(e);				
	if (e->fract == 2)
		ft_draw_burnship(e);
	if (e->fract == 3)
		ft_draw_tricorn(e);
	if (e->fract == 4)
		ft_draw_barnsley(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
}

int		main(int argc, char **argv)
{
    t_env e;

    if (argc != 2)
    {
		ft_putendl("usage : ./fractol \"mandelbrot\", \"julia\", \"burnship\", \"tricorn\", \"barnsley\"");
        exit(EXIT_SUCCESS);
    }
    else
        ft_checks_parameters(argv, &e);
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
    ft_create_image(&e);
    mlx_hook(e.win, 2, 0, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}
