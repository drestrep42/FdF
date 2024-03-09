/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/08 18:44:58 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_y_lines(t_map map)
{
	t_vector	vector;
	int			x;
	int			y;

	x = 0;
	while (x < map.x_nbrs)
	{
		vector.start_point.x = map.start_point.x + map.tile_size * x;
		vector.end_point.x = vector.start_point.x;
		y = 0;
		while (y < map.y_nbrs - 1)
		{
			vector.start_point.y = map.start_point.y + map.tile_size * y;
			vector.end_point.y = map.start_point.y + map.tile_size * (y + 1);
			vector.start_point.color = map.coord[y][x].color;
			vector.start_point.z = map.coord[y][x].z;
			vector.end_point.color = map.coord[y + 1][x].color;
			vector.end_point.z = map.coord[y + 1][x].z;
			bres(map, vector);
			y++;
		}
		x++;
	}
}

void	draw_x_lines(t_map map)
{
	t_vector	vector;
	int			x;
	int			y;

	y = 0;
	while (y < map.y_nbrs)
	{
		vector.start_point.y = map.start_point.y + map.tile_size * y;
		vector.end_point.y = vector.start_point.y;
		x = 0;
		while (x < map.x_nbrs - 1)
		{
			vector.start_point.x = map.start_point.x + map.tile_size * x;
			vector.end_point.x = map.start_point.x + map.tile_size * (x + 1);
			vector.start_point.color = map.coord[y][x].color;
			vector.start_point.z = map.coord[y][x].z;
			vector.end_point.color = map.coord[y][x + 1].color;
			vector.end_point.z = map.coord[y][x + 1].z;
			bres(map, vector);
			x++;
		}
		y++;
	}
}

void	draw_map(t_map map)
{
	draw_x_lines(map);
	draw_y_lines(map);
}
