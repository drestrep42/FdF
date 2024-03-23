/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:16:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 16:44:09 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void my_pixel_put(t_img *img, int x, int y, int color)
{
	int i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * img->bpp / 8) + (y * img->line_length);
		img->img_pixel_ptr[i] = color;
		img->img_pixel_ptr[++i] = color >> 8;
		img->img_pixel_ptr[++i] = color >> 16;
	}
}

int	interpolate(int start_color, int end_color, float t)
{
	if (start_color == end_color)
		return (start_color);
	return ((int)start_color + (end_color - start_color) * t);
}
