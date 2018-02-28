/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:00:53 by minh              #+#    #+#             */
/*   Updated: 2018/02/28 18:43:55 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_buddhabrot(t_env *e)
{
    e->bdt.zoom = 100;
    e->bdt.movex = TEST; 
    e->bdt.movey = TEST;
    e->bdt.max_iter = 100;
    e->bdt.c_re = TEST;
    e->bdt.c_im = TEST;  
}


ft_draw_buddhabrot(t_env *e)
{
    int x;
    int xtemp;
    int y;
    int ytemp;
    int iter;
    int itermax;
    int itermin;
    
    x = random();
    xtemp = 0;
    y = random();
    ytemp = 0;
    iter = 0;
    itermax = 10000;
    itermin = 50;

    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            while (xtemp * xtemp + ytemp * ytemp < 4 && iter < itermax) 
            {
                xtemp = xtemp * xtemp - ytemp * ytemp + x;
                ytemp = 2 * xtemp * ytemp + y;
                xtemp = xtem;
                iter=iter+1;
                }
            if ( iter < itermax && iter > itermin) 
            {
            e->mdb.rgb_color = hsv2rgb(ColorHSV(i % 256, 1.0, i < e->mdb.max_iter));
            ft_fill_pixel(e, x, y, createRGB(e->mdb.rgb_color.r, e->mdb.rgb_color.g, e->mdb.rgb_color.b)); 
            }
            y++;
        }
        x++;
    }
}



// en théorie, on devrait faire une seul boucle dans laquelle on devrait prendre les coordonnées (x; y) au hasard.
Pour x = 0 tant que x < image_x par pas de 1
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = x / zoom + x1
        définir c_i = y / zoom + y1
        définir z_r = 0
        définir z_i = 0
        définir i = 0
        définir tmp_pixels comme une liste de coordonnées

        Faire
            définir tmp = z_r
            z_r = z_r*z_r - z_i*z_i + c_r
            z_i = 2*z_i*tmp + c_i
            i = i+1
            ajouter les coordonnées ((z_r-x1)*zoom; (z_i-y1)*zoom) au tableau tmp_pixels
        Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

        si i != iteration_max
            Pour chaque valeurs pixel de tmp_pixels
                si la case pixels[pixel[0]][pixel[1]] existe
                    on incrémente la case en question
                finSi
            finPour
        finSi
    finPour
finPour

Pour chaque case de coordonnée (x; y) de l'image
    Dessiner le pixel de coordonnée (x; y) avec la couleur rgb(min(pixels[x][y], 255), min(pixels[x][y], 255), min(pixels[x][y], 255))
finPour