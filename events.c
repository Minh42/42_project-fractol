/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:42:32 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 17:48:30 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	e->julia.old_time = e->julia.current_time;
	e->julia.current_time = time(NULL);
	e->julia.frametime = e->julia.current_time - e->julia.old_time;
	if (keycode == EXIT)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		exit(EXIT_SUCCESS);
	}
	zoom_hook(keycode, e);
	move_hook(keycode, e);
	shape_hook(keycode, e);
	ft_redraw(e);
	return (0);
}

void	zoom_hook(int keycode, t_env *e)
{
	if (keycode == ZOOM_IN)
		e->julia.zoom *= pow(1.001, e->julia.frametime);
	if (keycode == ZOOM_OUT)
		e->julia.zoom /= pow(1.001, e->julia.frametime);
}

void	move_hook(int keycode, t_env *e)
{
	if (keycode == MOVE_DOWN)
		e->julia.movey += 0.0003 * e->julia.frametime / e->julia.zoom;
	if (keycode == MOVE_UP)
		e->julia.movey -= 0.0003 * e->julia.frametime / e->julia.zoom;
	if (keycode == MOVE_RIGHT)
		e->julia.movex += 0.0003 * e->julia.frametime / e->julia.zoom;
	if (keycode == MOVE_LEFT)
		e->julia.movex -= 0.0003 * e->julia.frametime / e->julia.zoom;
}

void	shape_hook(int keycode, t_env *e)
{
	if (keycode == CIM_UP)
		e->julia.c_im += 0.0002 * e->julia.frametime / e->julia.zoom;
	if (keycode == CIM_DOWN)
		e->julia.c_im -= 0.0002 * e->julia.frametime / e->julia.zoom;
	if (keycode == CRE_UP)
		e->julia.c_re += 0.0002 * e->julia.frametime / e->julia.zoom;
	if (keycode == CRE_DOWN)
		e->julia.c_re -= 0.0002 * e->julia.frametime / e->julia.zoom;
}