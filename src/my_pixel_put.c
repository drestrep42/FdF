/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:22:42 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 22:43:37 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * img->bpp / 8) + (y * img->line_length);
		img->img_pixel_ptr[i] = color;
		img->img_pixel_ptr[++i] = color >> 8;
		img->img_pixel_ptr[++i] = color >> 16;
	}
}
