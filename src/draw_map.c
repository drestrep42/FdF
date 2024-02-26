/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/25 22:35:44 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_y_lines(t_map map)
{
	t_vector vector;
	int	x;
	int	y;

	x = 0;
	while (x <= map.x_nbrs)
	{
		vector.start_point.x = map.start_point.x + map.tile_size * x;
		vector.end_point.x = vector.start_point.x;
		y = 0;
		while (y < map.y_nbrs)
		{
			vector.start_point.y = map.start_point.y + map.tile_size * y;
			vector.end_point.y = map.start_point.y + map.tile_size * (y + 1);
			//vector.start_point.color = map.coord[y][x].color;
			//vector.end_point.color = map.coord[y + 1][x].color;
			draw_line(map, vector);	
			y++;
		}
		x++;
	}
}

void	draw_x_lines(t_map map)
{
	t_vector vector;
	int	x;
	int	y;
	
	y = 0;
	while (y <= map.y_nbrs)
	{
		vector.start_point.y = map.start_point.y + map.tile_size * y;
		vector.end_point.y = vector.start_point.y;
		x = 0;
		while (x < map.x_nbrs)
		{
			vector.start_point.x = map.start_point.x + map.tile_size * x;
			vector.end_point.x = map.start_point.x + map.tile_size * (x + 1);
			//ft_printf("Map coord x: %d, y: %d, has %d color\n", y, x, map.coord[y][x].color);
			vector.start_point.color = map.coord[y][x].color;
			if (x == map.x_nbrs - 1)
			{
				ft_printf("color: %d\n", vector.start_point.color);
				exit(0);
			}
			if (x == map.x_nbrs - 1)
			{
				ft_printf("x: %d\n", x);
				vector.end_point.color = map.coord[y][x].color;
			}
			else
				vector.end_point.color = map.coord[y][x + 1].color;
			//ft_printf("End point in coord x: %d y: %d\n", x + 1, y);
			//ft_printf("Vector start point color: %d\nEnd point: %d\n", vector.start_point.color, vector.end_point.color);
			//vector.start_point.z = map.coord[y][x].z;
			//vector.end_point.z = map.coord[y][x + 1].z;
			draw_line(map, vector);
			x++;
			/* if (1)
			{
				ft_printf("Vector start point:\n\nX: %d\nY: %d\nZ: %d\nColor: %d\n\n\n", \
				vector.start_point.x, vector.start_point.y, vector.start_point.z);
				ft_printf("Vector end point:\n\nX: %d\nY: %d\nZ: %d\nColor: %d\n\n\n", \
				vector.end_point.x, vector.end_point.y, vector.end_point.z);
			} */
		}
		//ft_printf("x: %d\ny: %d\n", x, y);
		y++;
	}
}

void	draw_map(t_map map)
{
	if (map.x_nbrs == map.y_nbrs)
	{
		map.x_nbrs--;
		map.y_nbrs--;
	}
	//map.coord[3][5].color = BLUE;
	draw_x_lines(map);
	draw_y_lines(map);
}

	//
	//
	//
	//ft_printf("x0: %d xf: %d y0: %d yf: %d\n", fdf.map.points.x0, fdf.map.points.xf, fdf.map.vector.start_point.y , fdf.map.vector.end_point.y);
	//exit(0);
	//ft_printf("%d\n", fdf.map.points.color);
	//
	//
	//