/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:46:47 by minh              #+#    #+#             */
/*   Updated: 2018/03/07 14:19:41 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

t_hsv ColorHSV(float h, float s, float v)
{
    t_hsv hsv_color;

    hsv_color.h = h;
    hsv_color.s = s;
    hsv_color.v = v;
    return (hsv_color);
}

t_rgb ColorRGB(float r, float g, float b)
{
    t_rgb rgb_color;

    rgb_color.r = r;
    rgb_color.g = g;
    rgb_color.b = b;
    return (rgb_color);
}

t_rgb   hsv2rgb(t_hsv hsv_color)
{
    t_rgb   rgb_color;
    int     i;
    float   f;
    float   aa;
    float   bb;
    float   cc;
    float   sector;

    if (hsv_color.s == 0)
    {
        rgb_color.r = hsv_color.v;
        rgb_color.g = hsv_color.v;
        rgb_color.b = hsv_color.v;
    }
    sector = hsv_color.h / 60;
    i = floor(sector);
    f = sector - i;
    aa = hsv_color.v * (1 - hsv_color.s);
    bb = hsv_color.v * (1 - (hsv_color.s * f));
    cc = hsv_color.v * (1 - (hsv_color.s * (1 - f)));
    if (i == 0)
    {
        rgb_color.r = hsv_color.v;
        rgb_color.g = cc;
        rgb_color.b = aa;
    }
    else if (i == 1)
    {
        rgb_color.r = bb;
        rgb_color.g = hsv_color.v;
        rgb_color.b = aa;
    }
    else if (i == 2)
    {
        rgb_color.r = aa;
        rgb_color.g = hsv_color.v;
        rgb_color.b = cc;
    }
    else if (i == 3)
    {
        rgb_color.r = aa;
        rgb_color.g = bb;
        rgb_color.b = hsv_color.v;
    }
    else if (i == 4)
    {
        rgb_color.r = cc;
        rgb_color.g = aa;
        rgb_color.b = hsv_color.v;
    }
    else
    {
        rgb_color.r = hsv_color.v;
        rgb_color.g = aa;
        rgb_color.b = bb;
    }
    rgb_color.r = ((int)(rgb_color.r * 255.0));
    rgb_color.g = ((int)(rgb_color.g * 255.0));
    rgb_color.b = ((int)(rgb_color.b * 255.0));
    return (rgb_color);
}
