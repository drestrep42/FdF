/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:16:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/09 17:48:42 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = img->line_length * y + x * (img->bpp / 8);
	*(unsigned int *)(offset + img->img_pixel_ptr) = color;
}

int	interpolate(int start_color, int end_color, float t)
{
	if (start_color == end_color)
		return (start_color);
	return ((int)start_color + (end_color - start_color) * t);
}
