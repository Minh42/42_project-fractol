/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:33:03 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 19:11:12 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_burnship(t_env *e)
{
    e->mdb.zoom = 1;
    e->mdb.movex = -0.5; 
    e->mdb.movey = 0;
    e->mdb.max_iter = 300;
}

void    ft_draw_burnship(t_env *e)
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
            e->mdb.pr = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * e->mdb.zoom * WIN_WIDTH) + e->mdb.movex;
            e->mdb.pi = (y - WIN_HEIGHT / 2) / (0.5 * e->mdb.zoom * WIN_HEIGHT) + e->mdb.movey;
            e->mdb.new_re = e->mdb.new_im = e->mdb.old_re = e->mdb.old_im = 0;
            i = 0;
            while (i < e->mdb.max_iter)
            {
                e->mdb.old_re = e->mdb.new_re;
                e->mdb.old_im = e->mdb.new_im;
                e->mdb.new_re = ft_abs(e->mdb.old_re * e->mdb.old_re - e->mdb.old_im * e->mdb.old_im + e->mdb.pr);
                e->mdb.new_im = ft_abs(2 * e->mdb.old_re * e->mdb.old_im + e->mdb.pi);
                if ((e->mdb.new_re * e->mdb.new_re + e->mdb.new_im * e->mdb.new_im) > 4)
                    break;
                i++;
            }
            e->mdb.rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < e->mdb.max_iter));
            ft_fill_pixel(e, x, y, createRGB(e->mdb.rgb_color.r, e->mdb.rgb_color.g, e->mdb.rgb_color.b));               
            y++;
        }
        x++;
    }
}
