/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:49:22 by mpham             #+#    #+#             */
/*   Updated: 2018/03/07 16:44:33 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
            e->mdb.pr = e->re_min + ((e->re_max - e->re_min) / WIN_WIDTH * x) + e->movex;
            e->mdb.pi = e->im_min + ((e->im_max - e->im_min) / WIN_HEIGHT * y) + e->movey;
            e->mdb.new_re = e->mdb.new_im = e->mdb.old_re = e->mdb.old_im = 0;
            i = 0;
            while (i < e->max_iter)
            {
                e->mdb.old_re = e->mdb.new_re;
                e->mdb.old_im = e->mdb.new_im;
                e->mdb.new_re = ft_abs(e->mdb.old_re * e->mdb.old_re - e->mdb.old_im * e->mdb.old_im + e->mdb.pr);
                e->mdb.new_im = ft_abs(2 * e->mdb.old_re * e->mdb.old_im + e->mdb.pi);
                if ((e->mdb.new_re * e->mdb.new_re + e->mdb.new_im * e->mdb.new_im) > 4)
                    break;
                i++;
            }
            if (e->color > 256)
                e->color -= 256;
            if (e->color < 0)
                e->color += 256;
            e->mdb.rgb_color = hsv2rgb(ColorHSV(i % 256 + e->color, 1.0, i < e->max_iter));
            ft_fill_pixel(e, x, y, createRGB(e->mdb.rgb_color.r, e->mdb.rgb_color.g, e->mdb.rgb_color.b));               
            y++;
        }
        x++;
    }
}
