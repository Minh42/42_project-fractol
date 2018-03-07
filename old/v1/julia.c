/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:31:33 by minh              #+#    #+#             */
/*   Updated: 2018/03/07 10:45:45 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_draw_julia(t_env *e)
{
    int     i;
    int     x;
    int     y;
    
    e->julia.c_re = -0.7;
    e->julia.c_im = 0.27015;
    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            e->julia.new_re = e->re_min + ((e->re_max - e->re_min) / WIN_WIDTH * x) + e->movex;
            e->julia.new_im = e->im_min + ((e->im_max - e->im_min) / WIN_HEIGHT * y) + e->movey;
            i = 0;
            while (i < e->max_iter)   
            {
                e->julia.old_re = e->julia.new_re;
                e->julia.old_im = e->julia.new_im;
                e->julia.new_re = e->julia.old_re * e->julia.old_re - e->julia.old_im * e->julia.old_im + e->julia.c_re;
                e->julia.new_im = 2 * e->julia.old_re * e->julia.old_im + e->julia.c_im;
                if ((e->julia.new_re * e->julia.new_re + e->julia.new_im * e->julia.new_im) > 4)
                    break ;
                i++;
            }
            e->julia.rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < e->max_iter));
            ft_fill_pixel(e, x, y, createRGB(e->julia.rgb_color.r, e->julia.rgb_color.g, e->julia.rgb_color.b));
            y++;
        }
        x++;
    }
}
