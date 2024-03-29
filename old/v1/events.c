/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:42:32 by minh              #+#    #+#             */
/*   Updated: 2018/03/07 10:50:04 by mpham            ###   ########.fr       */
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
     e->re_min = interpolate(mouseRe, e->re_min, interpolation);
     e->im_min = interpolate(mouseIm, e->im_min, interpolation);
     e->re_max = interpolate(mouseRe, e->re_max, interpolation);
     e->im_max = interpolate(mouseIm, e->im_max, interpolation);
}

int		key_hook(int keycode, t_env *e)
{
// 	printf("%d", keycode);
// 	printf("\n");
// 	e->old_time = e->current_time;
// 	e->current_time = time(NULL);
// 	e->frametime = e->current_time - e->old_time;
	if (keycode == EXIT)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		exit(EXIT_SUCCESS);
	}
	// zoom_hook(keycode, e);
	move_hook(keycode, e);
	// shape_hook(keycode, e);
	ft_redraw(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	double mouseRe;
	double mouseIm;
	
	mouseRe = (double)x / (WIN_WIDTH / (e->re_max - e->re_min)) + e->re_min;
	mouseIm = (double)y / (WIN_HEIGHT / (e->im_max - e->im_min)) + e->im_min;
	if (button == CLIC_RIGHT)
		applyZoom(e, mouseRe, mouseIm, 1.2);
	if (button == CLIC_LEFT)
		applyZoom(e, mouseRe, mouseIm, 0.8);
	ft_redraw(e);
	return (0);
}

void	move_hook(int keycode, t_env *e)
{
	if (keycode == MOVE_DOWN)
		e->movey += 1;
	if (keycode == MOVE_UP)
		e->movey -= 1;
	if (keycode == MOVE_RIGHT)
		e->movex += 1;
	if (keycode == MOVE_LEFT)
		e->movex -= 1;
}


// void	zoom_hook(int keycode, t_env *e)
// {
// 	if (keycode == ZOOM_IN)
// 		e->julia.zoom *= pow(1.001, e->frametime);
// 	if (keycode == ZOOM_OUT)
// 		e->julia.zoom /= pow(1.001, e->frametime);
// }

// void	move_hook(int keycode, t_env *e)
// {
// 	if (keycode == MOVE_DOWN)
// 		e->julia.movey += 0.0003 * e->frametime / e->julia.zoom;
// 	if (keycode == MOVE_UP)
// 		e->julia.movey -= 0.0003 * e->frametime / e->julia.zoom;
// 	if (keycode == MOVE_RIGHT)
// 		e->julia.movex += 0.0003 * e->frametime / e->julia.zoom;
// 	if (keycode == MOVE_LEFT)
// 		e->julia.movex -= 0.0003 * e->frametime / e->julia.zoom;
// }

// void	shape_hook(int keycode, t_env *e)
// {
// 	if (keycode == CIM_UP)
// 		e->julia.c_im += 0.0002 * e->frametime / e->julia.zoom;
// 	if (keycode == CIM_DOWN)
// 		e->julia.c_im -= 0.0002 * e->frametime / e->julia.zoom;
// 	if (keycode == CRE_UP)
// 		e->julia.c_re += 0.0002 * e->frametime / e->julia.zoom;
// 	if (keycode == CRE_DOWN)
// 		e->julia.c_re -= 0.0002 * e->frametime / e->julia.zoom;
// }