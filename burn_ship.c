/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:33:03 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 15:00:56 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_draw_burnship(t_env *e)
{
	double pr, pi;           //real and imaginary part of the pixel p
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
 	double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
  	int maxIterations = 300;//after how much iterations the function should stop
	int x;
	int y;
	int i;
    t_rgb   rgb_color;
    
	x = 0;
  	while (x < WIN_WIDTH)
	{
		y = 0;
 		while (y < WIN_HEIGHT)
  		{
   			pr = 1.5 * (x - WIN_WIDTH / 2) / (0.4 * zoom * WIN_WIDTH) + moveX;
    		pi = (y - WIN_HEIGHT / 2) / (0.4 * zoom * WIN_HEIGHT) + moveY;
    		newRe = newIm = oldRe = oldIm = 0; 
			i = 0;
    		while (i < maxIterations)
    		{
      			oldRe = newRe;
      			oldIm = newIm;
     			newRe = ft_abs(oldRe * oldRe - oldIm * oldIm + pr);
      			newIm = ft_abs(2 * oldRe * oldIm + pi);
      			if((newRe * newRe + newIm * newIm) > 4) 
				  	break;
				i++;
			}
            rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < maxIterations));
            ft_fill_pixel(e, x, y, createRGB(rgb_color.r, rgb_color.g, rgb_color.b));
			y++;
		}
		x++;
    }
}