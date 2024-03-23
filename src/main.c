/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:14:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 17:20:28 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	leaks()
{
	system("leaks -q fdf");
}

void	zoom(int button, int x, int y, t_map *map)
{
	if (button == 4)
		map->zoom.value += 1;
	if (button == 5)
		map->zoom.value -= 1;
	map->zoom.x = x;
	map->zoom.y = y;
	ft_printf("%d\n", map->zoom);
}

int	mouse_hooks(int button, int x, int y, t_fdf *fdf)
{
	blackscreen(fdf->map);
	if (button == 4 || button == 5)
		zoom(button, x, y, &fdf->map);
	ft_printf("Button pressed in %d, %d\n", x, y);
	draw_map(fdf->map);
	mlx_put_image_to_window(fdf->mlx_ptr, \
	fdf->win_ptr, fdf->map.img.img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **argv)
{
	t_fdf	fdf;
	int		fd;

	//atexit(leaks);
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
	//fd = open(argv[1], O_RDONLY);
	//mlx_key_hook(fdf.win_ptr, handle_input, &fdf);
	mlx_key_hook(fdf.win_ptr, key_hooks, &fdf);
	mlx_mouse_hook(fdf.win_ptr, mouse_hooks, &fdf);
	mlx_hook(fdf.win_ptr, CLOSE_WINDOW, 0, close_win, &fdf);
	mlx_hook(fdf.win_ptr, KEY_DOWN, 0, events, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
