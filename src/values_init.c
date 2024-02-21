/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:25:33 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/21 17:11:55 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_array(char **ints)
{
	int	i;

	i = 0;
	while (ints && ints[i])
	{
		free(ints[i]);
		i++;
	}
}

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
