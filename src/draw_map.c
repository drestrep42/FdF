/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 17:26:47 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_y_lines(t_map map)
{
	int			x;
	int			y;

	x = 0;
	while (x < map.x_nbrs)
	{
		map.vector.start_point.x = map.start_point.x + (map.tile_size + map.zoom.value) * x;
		map.vector.end_point.x = map.vector.start_point.x;
		y = 0;
		while (y < map.y_nbrs - 1)
		{
			map.vector.start_point.y = map.start_point.y + (map.tile_size + map.zoom.value) * y;
			map.vector.end_point.y = map.start_point.y + (map.tile_size + map.zoom.value) * (y + 1);
			map.vector.start_point.color = map.coord[y][x].color;
			map.vector.start_point.z = map.coord[y][x].z * map.multiplier;
			map.vector.end_point.color = map.coord[y + 1][x].color;
			map.vector.end_point.z = map.coord[y + 1][x].z * map.multiplier;
			bres(map, map.vector);
			y++;
		}
		x++;
	}
}

void	draw_x_lines(t_map map)
{
	int			x;
	int			y;

	y = 0;
	while (y < map.y_nbrs)
	{
		map.vector.start_point.y = map.start_point.y + (map.tile_size + map.zoom.value) * y;
		map.vector.end_point.y = map.vector.start_point.y;
		x = 0;
		while (x < map.x_nbrs - 1)
		{
			map.vector.start_point.x = map.start_point.x + (map.tile_size + map.zoom.value) * x;
			map.vector.end_point.x = map.start_point.x + (map.tile_size + map.zoom.value) * (x + 1);
			map.vector.start_point.color = map.coord[y][x].color;
			map.vector.start_point.z = map.coord[y][x].z * map.multiplier;
			map.vector.end_point.color = map.coord[y][x + 1].color;
			map.vector.end_point.z = map.coord[y][x + 1].z * map.multiplier;
			bres(map, map.vector);
			x++;
		}
		y++;
	}
}

void	draw_map(t_map map)
{/* 
	static int	i = 0;
	ft_printf("Height: %d\n", map.multiplier);
	if (i == 2)
		exit(0); */
	draw_x_lines(map);
	draw_y_lines(map);
	//i++;
}
