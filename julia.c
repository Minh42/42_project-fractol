/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:31:33 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 17:39:35 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_julia_set(t_env *e)
{
    e->julia.zoom = 1;
    e->julia.movex = 0; 
    e->julia.movey = 0;
    e->julia.max_iter = 300;
    e->julia.c_re = -0.7;
    e->julia.c_im = 0.27015;  
}

void    ft_draw_julia(t_env *e)
{
    int     i;
    int     x;
    int     y;
    
    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            e->julia.new_re = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * e->julia.zoom * WIN_WIDTH) + e->julia.movex;
            e->julia.new_im = (y - WIN_HEIGHT / 2) / (0.5 * e->julia.zoom * WIN_HEIGHT) + e->julia.movey;
            i = 0;
            while (i < e->julia.max_iter)   
            {
                e->julia.old_re = e->julia.new_re;
                e->julia.old_im = e->julia.new_im;
                e->julia.new_re = e->julia.old_re * e->julia.old_re - e->julia.old_im * e->julia.old_im + e->julia.c_re;
                e->julia.new_im = 2 * e->julia.old_re * e->julia.old_im + e->julia.c_im;
                if ((e->julia.new_re * e->julia.new_re + e->julia.new_im * e->julia.new_im) > 4)
                    break ;
                i++;
            }
            e->julia.rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < e->julia.max_iter));
            ft_fill_pixel(e, x, y, createRGB(e->julia.rgb_color.r, e->julia.rgb_color.g, e->julia.rgb_color.b));
            y++;
        }
        x++;
    }
}