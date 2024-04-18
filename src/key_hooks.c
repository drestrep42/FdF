/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:15 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 22:32:34 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(t_fdf fdf)
{
	(void)fdf;
	exit(0);
}

void	blackscreen(t_img img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(&img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	change_projection(int keysym, t_map *map)
{
	if (keysym == I)
		map->projection = 'I';
	else if (keysym == P)
		map->projection = 'P';
}

int	key_hooks(int keysym, t_fdf *fdf)
{
	blackscreen(fdf->img);
	if (keysym == ESC)
		close_win(*fdf);
	else if (keysym == R || keysym == G || keysym == B)
		color_map(keysym, &fdf->map);
	else if (keysym == I || keysym == P)
		change_projection(keysym, &fdf->map);
	draw_map(fdf, fdf->map);
	return (0);
}
