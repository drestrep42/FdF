/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:47:15 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/16 00:51:01 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_map_pararell(int keysym, t_map *map)
{
	if (keysym == LEFT_KEY)
	{
		map->start_point.x -= 10;
		map->end_point.x -= 10;
	}
	if (keysym == RIGHT_KEY)
	{
		map->start_point.x += 10;
		map->end_point.x += 10;
	}
	if (keysym == DOWN_KEY)
	{
		map->start_point.y += 10;
		map->end_point.y += 10;
	}
	if (keysym == UP_KEY)
	{
		map->start_point.y -= 10;
		map->end_point.y -= 10;
	}
}

void	move_map_iso(int keysym, t_map *map)
{
	if (keysym == LEFT_KEY || keysym == UP_KEY)
	{
		map->start_point.x -= 10;
		map->end_point.x -= 10;
	}
	if (keysym == LEFT_KEY || keysym == DOWN_KEY)
	{
		map->start_point.y += 10;
		map->end_point.y += 10;
	}
	if (keysym == RIGHT_KEY || keysym == DOWN_KEY)
	{
		map->start_point.x += 10;
		map->end_point.x += 10;
	}
	if (keysym == RIGHT_KEY || keysym == UP_KEY)
	{
		map->start_point.y -= 10;
		map->end_point.y -= 10;
	}
}

void	move_map(int keysym, t_map *map)
{
	if (map->projection == 'I')
		move_map_iso(keysym, map);
	if (map->projection == 'P')
		move_map_pararell(keysym, map);
}
