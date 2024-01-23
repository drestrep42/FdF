/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:26:37 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/20 20:37:46 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


/* void	move_map(t_fdf fdf, int keysym)
{
	t_img	next_frame;
	next_frame = img_init(fdf.mlx_ptr);
	if (keysym == 123)
	{
		next_frame.points.x0 = fdf.map.img.points.x0--;
		next_frame.points.xf = fdf.map.img.points.xf--;
	}
	else if (keysym == 124)
	{
		next_frame.points.x0 = fdf.map.img.points.x0++;
		next_frame.points.xf = fdf.map.img.points.xf++;
	}
	else if (keysym == 125)
	{
		next_frame.points.y0 = fdf.map.img.points.y0++;
		next_frame.points.yf = fdf.map.img.points.yf++;
	}
	else if (keysym == 126)
	{
		next_frame.points.y0 = fdf.map.img.points.y0--;
		next_frame.points.yf = fdf.map.img.points.yf--;
	}
	draw_line(fdf, next_frame.points);
	mlx_destroy_image(fdf.mlx_ptr, fdf.map.img.img_pixel_ptr);
	ft_printf("Imagen destruida\n");
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr,
		fdf.map.next_frame.img_ptr, 0, 0);
} */
