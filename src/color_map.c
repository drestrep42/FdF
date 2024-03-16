/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:52:32 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/16 00:54:08 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void change_color(t_map *map, int color)
{
	int x;
	int y;

	y = 0;
	while (y < map->y_nbrs)
	{
		x = 0;
		while (x < map->x_nbrs)
		{
			map->coord[y][x].color = color;
			x++;
		}
		y++;
	}
}

void color_map(int keysym, t_map *map)
{
	if (keysym == R)
		change_color(map, RED);
	if (keysym == G)
		change_color(map, GREEN);
	if (keysym == B)
		change_color(map, BLUE);
	if (keysym == W)
		change_color(map, WHITE);
}
