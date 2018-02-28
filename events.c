/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:42:32 by minh              #+#    #+#             */
/*   Updated: 2018/02/20 21:42:53 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == EXIT)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}