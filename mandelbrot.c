/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:52:47 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 14:50:51 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_draw_mandelbrot(t_env *e)
{
    int i, x, y;
    double pr, pi;
    double newRe, newIm, oldRe, oldIm;
    double zoom = 1, moveX = -0.5, moveY = 0;
    int maxIterations = 300;
    t_rgb   rgb_color;
    
    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            pr = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * zoom * WIN_WIDTH) + moveX;
            pi = (y - WIN_HEIGHT / 2) / (0.5 * zoom * WIN_HEIGHT) + moveY;
            newRe = newIm = oldRe = oldIm = 0;
            i = 0;
            while (i < maxIterations)
            {
                oldRe = newRe;
                oldIm = newIm;
                newRe = oldRe * oldRe - oldIm * oldIm + pr;
                newIm = 2 * oldRe * oldIm + pi;
                if ((newRe * newRe + newIm * newIm) > 4)
                    break;
                i++;
            }
             if (i == maxIterations)
                mlx_pixel_put(e->mlx, e->win, x, y, 255255255);
            else
            {
            rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < maxIterations));
            ft_fill_pixel(e, x, y, createRGB(rgb_color.r, rgb_color.g, rgb_color.b));
            
            //mlx_pixel_put(e->mlx, e->win, x, y, createRGB(rgb_color.r, rgb_color.g, rgb_color.b));                 
            }

            y++;
        }
        x++;
    }
}




// void    ft_draw_mandelbrot(t_env *e)
// {
//     int i;
//     int imax;
//     double x, x1, x2, y, y1, y2;
//     double zoom;
//     double image_x;
//     double image_y;
//     double c_r;
//     double c_i;
//     double z_r;
//     double z_i;
//     int tmp;

//     imax = 50;
//     x1 = -2.1;
//     x2 = 0.6;
//     y1 = -1.2;
//     y2 = 1.2;
//     zoom = 100;
//     image_x = (x2 - x1) * zoom;
//     image_y = (y2 - y1) * zoom;
    
//     x = 0;
//     while (x < image_x)
//     {
//         y = 0;
//         while (y < image_y)
//         {
//             c_r = x / zoom + x1;
//             c_i = y / zoom + x1;
//             z_r = 0;
//             z_i = 0;
//             i = 0;
//             while (z_r*z_r + z_i*z_i < 4 && i < imax)
//             {
//                 tmp = z_r;
//                 z_r = z_r*z_r - z_i*z_i + c_r;
//                 z_i = 2*z_i*tmp + c_i;
//                 i++;              
//             }   
//             if (i == imax)
//                 mlx_pixel_put(e->mlx, e->win, x, y, 255255255);
//             else
//                 mlx_pixel_put(e->mlx, e->win, x, y, createRGBA(0, 0, i*255/imax, 255));
//             y++;
//         }  
//         x++;
//     }  
// }
