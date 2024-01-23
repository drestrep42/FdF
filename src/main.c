/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:14:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/22 18:43:38 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	initialize_values(t_map map)
{
	map.points.x0 = WIDTH * 0.25;
	map.points.y0 = HEIGHT * 0.25;
	map.points.xf = WIDTH * 0.75;
	map.points.yf = HEIGHT * 0.75;
	map.width = map.points.xf - map.points.x0;
	map.height = map.points.yf - map.points.y0;
	if (map.x_nbrs > map.y_nbrs)
		map.tile_size = map.width / map.x_nbrs;
	else
		map.tile_size = map.height / map.y_nbrs;
	if (map.x_nbrs != map.y_nbrs)
	{
		map.points.x0 = map.points.x0 + map.width / 2 - map.x_nbrs / 2 * map.tile_size;
		map.points.y0 = map.points.y0 + map.height / 2 - map.y_nbrs / 2 * map.tile_size;
	}
	return (map);
}

/* ft_printf("\nNumbers on the X axis: %d\nNumbers on the Y axis: %d\nMap width: %d\nTile size: %d\n",
	map.x_nbrs, map.y_nbrs, map.width, map.img.tile_size);
	exit(0);
	ft_printf("\n\nx0: %d\nxf: %d\ny0: %d\nyf: %d\n", map.img.points.x0, map.img.points.xf, map.img.points.y0, map.img.points.yf);
	exit(0); */

int	main(int ac, char **argv)
{	
	t_fdf	fdf;
	int		fd;

	if (ac != 2 || ft_memcmp(argv[1], "", 1) == 0
		|| !((fd = open(argv[1], O_RDONLY)) >= 0))
	{
		printf(ERROR_USAGE);
		exit(1);
	}
	fdf = fdf_init();
	fdf.map = read_map(fdf.map, fd);
	close(fd);
	fdf.map = initialize_values(fdf.map);
	mlx_key_hook(fdf.win_ptr, handle_input, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_win, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
