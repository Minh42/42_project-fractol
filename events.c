/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:42:32 by minh              #+#    #+#             */
/*   Updated: 2018/03/07 17:14:27 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		key_hook(int keycode, t_env *e)
{
	printf("%d", keycode);
	printf("\n");
	if (keycode == EXIT)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == FREEZE)
	{
		if (e->freeze == 0)
			e->freeze = 1;
		else if (e->freeze == 1)
			e->freeze = 0;
	}
	if (keycode == ITER_UP)
		e->max_iter += 50;
	if (keycode == ITER_DOWN)
		e->max_iter -= 50;
	if (keycode == PAGE_UP)
		e->color += 20;
	if (keycode == PAGE_DOWN)
		e->color -= 20;
	if (keycode == MANDELBROT)
		e->fract = 0;
	if (keycode == JULIA)
	{
		e->fract = 1;
		init_julia_set(e);	
	}
	if (keycode == BURNSHIP)
		e->fract = 2;
	if (keycode == TRICORN)
		e->fract = 3;
	if (keycode == BARNSLEY)
		e->fract = 4;
	move_hook(keycode, e);
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

int		zoom_hook(int button, int x, int y, t_env *e)
{
	double mouseRe;
	double mouseIm;

	printf("%d", button);
	printf("\n");
	mouseRe = (double)x / (WIN_WIDTH / (e->re_max - e->re_min)) + e->re_min;
	mouseIm = (double)y / (WIN_HEIGHT / (e->im_max - e->im_min)) + e->im_min;
	if (button == SCROLL_UP)
	{
		e->zoomFactor = 1.2;
		applyZoom(e, mouseRe, mouseIm, e->zoomFactor);
	}
	if (button == SCROLL_DOWN)
	{
		e->zoomFactor = 0.8;
		applyZoom(e, mouseRe, mouseIm, e->zoomFactor);	
	}
	ft_redraw(e);
	return (0);
}

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

int		motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT && e->freeze != 1)
	{
		if (x <= WIN_WIDTH / 2)
		{
			e->julia.c_re += 0.01;
			e->julia.c_im += 0.01;
		}
		if (x >= WIN_WIDTH / 2)
		{
			e->julia.c_re -= 0.01;
			e->julia.c_im -= 0.01;
		}
	}
	ft_redraw(e);
	return (0);
}
