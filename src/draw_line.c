/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:27:12 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/16 00:43:22 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_error(t_bresenham bresenham, t_vector vector)
{
	if (bresenham.e2 > -vector.dy)
		bresenham.err -= vector.dy;
	if (bresenham.e2 < vector.dx)
		bresenham.err += vector.dx;
	return (bresenham.err);
}

t_points	get_next_point(t_bresenham bresenham, t_vector vector)
{
	if (bresenham.e2 > -vector.dy)
		vector.start_point.x += bresenham.sx;
	if (bresenham.e2 < vector.dx)
		vector.start_point.y += bresenham.sy;
	return (vector.start_point);
}

int	count_steps(t_vector vector, t_bresenham bresenham)
{
	int		steps;

	steps = 0;
	while (vector.start_point.x != vector.end_point.x
		|| vector.start_point.y != vector.end_point.y)
	{
		bresenham.e2 = 2 * bresenham.err;
		if (bresenham.e2 > -vector.dy)
		{
			bresenham.err -= vector.dy;
			vector.start_point.x += bresenham.sx;
		}
		if (bresenham.e2 < vector.dx)
		{
			bresenham.err += vector.dx;
			vector.start_point.y += bresenham.sy;
		}
		steps++;
	}
	return (steps);
}

void	draw_pixels(t_map map, t_vector vector, t_bresenham bresenham)
{
	float	step_size;
	float	t;
	int		steps;
	int		gradient;
	int		i;

	steps = count_steps(vector, bresenham);
	step_size = 1.0 / steps;
	i = 0;
	while (i < steps)
	{
		t = i * step_size;
		gradient = interpolate(vector.start_point.color, \
		vector.end_point.color, t);
		if (vector.start_point.x > 0 && vector.start_point.x < WIDTH \
			&& vector.start_point.y > 0 && vector.end_point.y < HEIGHT)
			my_pixel_put(&map.img, vector.start_point.x, \
			vector.start_point.y, gradient);
		bresenham.e2 = 2 * bresenham.err;
		bresenham.err = get_error(bresenham, vector);
		vector.start_point = get_next_point(bresenham, vector);
		i++;
	}
}

void	bres(t_map map, t_vector vector)
{
	t_bresenham	bresenham;

	if (map.projection == 'I')
	{
		vector.start_point = rotation_matrices(vector.start_point);
		vector.end_point = rotation_matrices(vector.end_point);
	}
	else if (map.projection == 'P')
	{
		vector.start_point = vector.start_point;
		vector.end_point = vector.end_point;
	}
	vector.dx = abs(vector.end_point.x - vector.start_point.x);
	vector.dy = abs(vector.end_point.y - vector.start_point.y);
	bresenham.err = vector.dx - vector.dy;
	if (vector.start_point.x < vector.end_point.x)
		bresenham.sx = 1;
	else
		bresenham.sx = -1;
	if (vector.start_point.y < vector.end_point.y)
		bresenham.sy = 1;
	else
		bresenham.sy = -1;
	draw_pixels(map, vector, bresenham);
}
