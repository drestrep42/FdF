/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:15 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 16:26:13 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(t_fdf fdf)
{
	(void)fdf;
	exit(0);
}

void blackscreen(t_map map)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(&map.img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void change_projection(int keysym, t_map *map)
{
	if (keysym == I)
		map->projection = 'I';
	if (keysym == P)
		map->projection = 'P';
}

int key_hooks(int keysym, t_fdf *fdf)
{
	ft_printf("The key %d has been pressed\n", keysym);
	blackscreen(fdf->map);
	if (keysym == ESC)
		exit(0);
	if (keysym == ENTER)
		draw_map(fdf->map);
	/* if ((keysym >= 123 && keysym <= 126) ||
		(keysym >= 0 && keysym <= 2) || keysym == 13)
		move_map(keysym, &fdf->map); */
	if (keysym == R || keysym == G || keysym == B)
		color_map(keysym, &fdf->map);
	if (keysym == I || keysym == P)
		change_projection(keysym, &fdf->map);
	draw_map(fdf->map); // SE EJECUTA CON CUALQUIER TECLA
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->map.img.img_ptr, 0, 0);
	return (0);
}