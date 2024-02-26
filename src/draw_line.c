/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:27:12 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/25 21:04:37 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = img->line_length * y + x * (img->bpp / 8);
	*(unsigned int *)(offset + img->img_pixel_ptr) = color;
}

void	smaller_than_1(t_map map, t_vector vector)
{
	t_points	current_point;
	int			i;
	int			p;
	int			t;

	current_point = vector.start_point;
	i = 0;
	p = 2 * vector.dy - vector.dx;
	while (i < vector.dx)
	{
		t = i * (vector.dx / map.tile_size);
		current_point = change_values_0(vector, current_point, p, t);
		my_pixel_put(&map.img, current_point.x, current_point.y,
			RED);
		i++;
	}
}

void	bigger_than_1(t_map map, t_vector vector)
{
	t_points	current_point;
	static int	p;
	int			i;
	int			t;

	current_point = vector.start_point;
	p = 2 * vector.dx - vector.dy;
	i = 0;
	while (i < vector.dy)
	{
		t = i * (vector.dy / map.tile_size);
		current_point = change_values_1(vector, current_point, p, t);
		my_pixel_put(&map.img, current_point.x, current_point.y,
			RED);
		i++;
	}
}

void	draw_line(t_map map, t_vector vector)
{
	int	slope;

	vector.dx = abs(vector.end_point.x - vector.start_point.x);
	vector.dy = abs(vector.end_point.y - vector.start_point.y);
	if (vector.dx == 0)
		slope = 1;
	else if (vector.dy == 0)
		slope = 0;
	else
		slope = vector.dy / vector.dx;
	if (slope >= 1)
		bigger_than_1(map, vector);
	else
		smaller_than_1(map, vector);
}

	/* ft_printf("x0: %d\nxf: %d\ny0: %d\nyf: %d\n", \
	fdf.map.img.points.x0, fdf.map.img.points.xf, \
	fdf.map.img.points.y0, fdf.map.img.points.yf);
	exit(0); */