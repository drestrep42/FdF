/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:27:12 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/23 18:58:01 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	
my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = img->line_length * y + x * (img->bpp / 8);
	*(unsigned int *)(offset + img->img_pixel_ptr) = color;
}

void	smaller_than_1(t_fdf fdf, t_points points, int abs_dx, int abs_dy)
{
	int	i;
	int	p;

	i = 0;
	p = 2 * abs_dy - abs_dx;
	while (i < abs_dx)
	{
		if (points.dx < 0)
			points.x0--;
		else
			points.x0++;
		if (p >= 0)
		{
			p = p + 2 * (abs_dy - abs_dx);
			if (points.dy < 0)
				points.y0--;
			else
				points.y0++;
		}
		else
			p = p + 2 * abs_dy;
		my_pixel_put(&fdf.map.img, points.x0, points.y0, RED);
		i++;
	}
}

void	bigger_than_1(t_fdf fdf, t_points points, int abs_dx, int abs_dy)
{
	int	i;
	int	p;

	i = 0;
	p = 2 * abs_dx - abs_dy;
	while (i < abs_dy)
	{
		if (points.dy < 0)
			points.y0--;
		else
			points.y0++;
		if (p >= 0)
		{
			p = p + 2 * (abs_dx - abs_dy);
			if (points.dx < 0)
				points.x0--;
			else
				points.x0++;
		}
		else
			p = p + 2 * abs_dx;
		my_pixel_put(&fdf.map.img, points.x0, points.y0, 0x00FF0000);
		i++;
	}
}

void	draw_line(t_fdf fdf, t_points points)
{
	int	abs_dx;
	int	abs_dy;
	int	slope;

	points.dx = points.xf - points.x0;
	points.dy = points.yf - points.y0;
	abs_dx = abs(points.dx);
	abs_dy = abs(points.dy);
	if (abs_dx == 0)
		slope = 1;
	else if (abs_dy == 0)
		slope = 0;
	else
		slope = abs_dy / abs_dx;
	if (slope >= 1)
		bigger_than_1(fdf, points, abs_dx, abs_dy);
	else
		smaller_than_1(fdf, points, abs_dx, abs_dy);
}

	/* ft_printf("x0: %d\nxf: %d\ny0: %d\nyf: %d\n", fdf.map.img.points.x0, fdf.map.img.points.xf, fdf.map.img.points.y0, fdf.map.img.points.yf);
	exit(0); */