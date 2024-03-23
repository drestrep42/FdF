/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:47:15 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 16:50:59 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void change_height(int keysym, t_map *map)
{
	if (keysym == MINUS)
		map->multiplier -= 1.5;
	if (keysym == PLUS)
		map->multiplier += 1.5;
}

void	move_map_pararell(int keysym, t_map *map)
{
	if (keysym == LK || keysym == A)
	{
		map->start_point.x -= 10;
		map->end_point.x -= 10;
	}
	if (keysym == RK || keysym == D)
	{
		map->start_point.x += 10;
		map->end_point.x += 10;
	}
	if (keysym == DK || keysym == S)
	{
		map->start_point.y += 10;
		map->end_point.y += 10;
	}
	if (keysym == UK || keysym == W)
	{
		map->start_point.y -= 10;
		map->end_point.y -= 10;
	}
}

void	move_map_iso(int keysym, t_map *map)
{
	if (keysym == LK || keysym == UK || keysym == A || keysym == W)
	{
		map->start_point.x -= 10;
		map->end_point.x -= 10;
	}
	if (keysym == LK || keysym == DK || keysym == A || keysym == S)
	{
		map->start_point.y += 10;
		map->end_point.y += 10;
	}
	if (keysym == RK || keysym == DK || keysym == D || keysym == S)
	{
		map->start_point.x += 10;
		map->end_point.x += 10;
	}
	if (keysym == RK || keysym == UK || keysym == D || keysym == W)
	{
		map->start_point.y -= 10;
		map->end_point.y -= 10;
	}
}

int	events(int keysym, t_fdf *fdf)
{
	blackscreen(fdf->map);
	if (fdf->map.projection == 'I')
		move_map_iso(keysym, &fdf->map);
	if (fdf->map.projection == 'P')
		move_map_pararell(keysym, &fdf->map);
	if (keysym == MINUS || keysym == PLUS)
		change_height(keysym, &fdf->map);
	draw_map(fdf->map);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->map.img.img_ptr, 0, 0);
	return (0);
}
