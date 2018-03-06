/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:42:32 by minh              #+#    #+#             */
/*   Updated: 2018/03/06 19:33:26 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void applyZoom(t_env* e, double mouseRe, double mouseIm, double zoomFactor)
{
     double interpolation = 1.0 / zoomFactor;
     e->julia.re_min = interpolate(mouseRe, e->julia.re_min, interpolation);
     e->julia.im_min = interpolate(mouseIm, e->julia.im_min, interpolation);
     e->julia.re_max = interpolate(mouseRe, e->julia.re_max, interpolation);
     e->julia.im_max = interpolate(mouseIm, e->julia.im_max, interpolation);
}

int		key_hook(int keycode, t_env *e)
{
	printf("%d", keycode);
	printf("\n");
	e->old_time = e->current_time;
	e->current_time = time(NULL);
	e->frametime = e->current_time - e->old_time;
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

int		mouse_hook(int button, int x, int y, t_env *e)
{
	double mouseRe;
	double mouseIm;
	
	mouseRe = (double)x / (WIN_WIDTH / (e->julia.re_max - e->julia.re_min)) + e->julia.re_min;
	mouseIm = (double)y / (WIN_HEIGHT / (e->julia.im_max - e->julia.im_min)) + e->julia.im_min;
	if (button == CLIC_RIGHT)
		applyZoom(e, mouseRe, mouseIm, 2);
	ft_redraw(e);
	return (0);
}

void	zoom_hook(int keycode, t_env *e)
{
	if (keycode == ZOOM_IN)
		e->julia.zoom *= pow(1.001, e->frametime);
	if (keycode == ZOOM_OUT)
		e->julia.zoom /= pow(1.001, e->frametime);
}

void	move_hook(int keycode, t_env *e)
{
	if (keycode == MOVE_DOWN)
		e->julia.movey += 0.0003 * e->frametime / e->julia.zoom;
	if (keycode == MOVE_UP)
		e->julia.movey -= 0.0003 * e->frametime / e->julia.zoom;
	if (keycode == MOVE_RIGHT)
		e->julia.movex += 0.0003 * e->frametime / e->julia.zoom;
	if (keycode == MOVE_LEFT)
		e->julia.movex -= 0.0003 * e->frametime / e->julia.zoom;
}

void	shape_hook(int keycode, t_env *e)
{
	if (keycode == CIM_UP)
		e->julia.c_im += 0.0002 * e->frametime / e->julia.zoom;
	if (keycode == CIM_DOWN)
		e->julia.c_im -= 0.0002 * e->frametime / e->julia.zoom;
	if (keycode == CRE_UP)
		e->julia.c_re += 0.0002 * e->frametime / e->julia.zoom;
	if (keycode == CRE_DOWN)
		e->julia.c_re -= 0.0002 * e->frametime / e->julia.zoom;
}