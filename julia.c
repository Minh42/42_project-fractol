/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:31:33 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 14:53:46 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_draw_julia(t_env *e)
{
    int i, x, y;
    double cRe, cIm;
    double newRe, newIm, oldRe, oldIm;
    double zoom = 1, moveX = 0, moveY = 0;
    int maxIterations = 300;
    t_rgb   rgb_color;

    cRe = -0.7;
    cIm = 0.27015;
    
    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            newRe = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * zoom * WIN_WIDTH) + moveX;
            newIm = (y - WIN_HEIGHT / 2) / (0.5 * zoom * WIN_HEIGHT) + moveY;
            i = 0;
            while (i < maxIterations)   
            {
                oldRe = newRe;
                oldIm = newIm;
                newRe = oldRe * oldRe - oldIm * oldIm + cRe;
                newIm = 2 * oldRe * oldIm + cIm;
                if ((newRe * newRe + newIm * newIm) > 4)
                    break ;
                i++;
            }
            rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < maxIterations));
            ft_fill_pixel(e, x, y, createRGB(rgb_color.r, rgb_color.g, rgb_color.b));
            //mlx_pixel_put(e->mlx, e->win, x, y, createRGB(rgb_color.r, rgb_color.g, rgb_color.b));  
            y++;
        }
        x++;
    }
}