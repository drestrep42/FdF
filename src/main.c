/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:14:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/16 00:57:34 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	leaks()
{
	system("leaks -q fdf");
}

void	blackscreen(t_map map)
{
	int	x;
	int	y;

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

void	change_height(int keysym, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->y_nbrs)
	{
		x = 0;
		while (x < map->x_nbrs)
		{
			if (keysym == MINUS && map->coord[y][x].z > 0)
				map->coord[y][x].z -= 5;
			if (keysym == PLUS && map->coord[y][x].z > 0)
				map->coord[y][x].z += 5;
			x++;
		}
		y++;
	}
}

void	change_projection(int keysym, t_map *map)
{
	if (keysym == I)
		map->projection = 'I';
	if (keysym == P)
		map->projection = 'P';
}

int	move_left(int keysym, t_fdf *fdf)
{
	ft_printf("The key %d has been pressed\n", keysym);
	blackscreen(fdf->map);
	if (keysym == ESC)
		exit(0);
	if (keysym == ENTER)
		draw_map(fdf->map);
	if (keysym >= 123 && keysym <= 126)
		move_map(keysym, &fdf->map);
	if (keysym == R || keysym == G || keysym == B)
		color_map(keysym, &fdf->map);
	if (keysym == I || keysym == P)
		change_projection(keysym, &fdf->map);
	if (keysym == MINUS || keysym == PLUS)
		change_height(keysym, &fdf->map);
	draw_map(fdf->map); // SE EJECUTA CON CUALQUIER TECLA
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->map.img.img_ptr, 0, 0);
	return (0);
}

/* int	zoom(t_fdf fdf)
{
	ft_printf
} */

int	main(int ac, char **argv)
{
	t_fdf	fdf;
	int		fd;

	atexit(leaks);
	fd = open(argv[1], O_RDONLY);
	if (ac != 2 || ft_memcmp(argv[1], "", 1) == 0 || fd < 0)
		usage_error();
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		usage_error();
	fdf = fdf_init();
	parsing(&fdf.map, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_init(&fdf.map);
	points_init(&fdf.map, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	//mlx_key_hook(fdf.win_ptr, handle_input, &fdf);
	mlx_key_hook(fdf.win_ptr, move_left, &fdf);
	//mlx_mouse_hook(fdf.win_ptr, zoom, &fdf);
	mlx_hook(fdf.win_ptr, CLOSE_WINDOW, 0, close_win, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
