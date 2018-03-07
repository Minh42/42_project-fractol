/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:49:10 by mpham             #+#    #+#             */
/*   Updated: 2018/03/07 17:23:59 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_draw_barnsley(t_env *e)
{
    double          x0;
    double          y0;
    double          x1;
    double          y1;
    int             random;
    unsigned long   iter;
    t_rgb           rgb_color;
	time_t          t;
	
    x0 = 0;
    y0 = 0;
    iter = 500000;
    srand((unsigned)time(&t));

    while (iter > 0)
    {
        random = rand() % 100;
		if (random == 0)
        {
			x1 = 0;
			y1 = 0.16 * y0;
		}
		else if (random >= 1 && random <= 7)
        {
			x1 = -0.15 * x0 + 0.28 * y0;
			y1 = 0.26 * x0 + 0.24 * y0 + 0.44;
		}
 
		else if(random >= 8 && random <= 15)
        {
			x1 = 0.2 * x0 - 0.26 * y0;
			y1 = 0.23 * x0 + 0.22 * y0 + 1.6;
		}
		else
        {
			x1 = 0.85 * x0 + 0.04 * y0;
			y1 = -0.04 * x0 + 0.85 * y0 + 1.6;
		}
        rgb_color = hsv2rgb(ColorHSV(120, 1.0, 0.5));
        ft_fill_pixel(e, 110 * x1 + WIN_WIDTH / 2.0, 110 * y1, createRGB(rgb_color.r, rgb_color.g, rgb_color.b));
		x0 = x1;
		y0 = y1;
		iter--;
	}
}
