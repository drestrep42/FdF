/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:53:51 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/21 16:36:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_z_values(t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char 	**int_array;

	y = 0;
	line = get_next_line(fd);
	map->coord = ft_calloc(map->y_nbrs + 1, sizeof(t_points *));
	while (y < map->y_nbrs)
	{
		int_array = ft_split(line, ' ');
		map->coord[y] = ft_calloc(map->x_nbrs + 1, sizeof(t_points));
		x = 0;
		while (x < map->x_nbrs)
		{
			map->coord[y][x].x = x;
			map->coord[y][x].y = y;
			map->coord[y][x].z = ft_atoi(int_array[x]);
			//ft_printf("%d ", map->coord[y][x].z);
			x++;
		}
		free_array(int_array);
		free(line);
		//ft_printf("\n");
		line = get_next_line(fd);
		y++;
	}
	free(line);
}
