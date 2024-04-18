/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:53:51 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 21:48:18 by drestrep         ###   ########.fr       */
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
	free(ints);
}

void	assign_coord_values(t_map *map, t_points position, char **int_array)
{
	char	*hex_value;
	int		height;

	while (position.x < map->x_nbrs)
	{
		height = ft_atoi(int_array[position.x]);
		map->coord[position.y][position.x].z = height;
		if (!ft_strchr(int_array[position.x], ','))
			map->coord[position.y][position.x].color = WHITE;
		else
		{
			hex_value = ft_strchr(int_array[position.x], ',') + 1;
			map->coord[position.y][position.x].color = ft_atoi_base(hex_value);
		}
		position.x++;
	}
}

void	points_init(t_map *map, int fd)
{
	t_points	position;
	char		*line;
	char		**int_array;

	position.y = 0;
	line = get_next_line(fd);
	ft_bzero(&position, sizeof(position));
	map->coord = ft_calloc(map->y_nbrs + 1, sizeof(t_points *));
	while (position.y < map->y_nbrs)
	{
		map->coord[position.y] = ft_calloc(map->x_nbrs + 1, sizeof(t_points));
		int_array = ft_split(line, ' ');
		assign_coord_values(map, position, int_array);
		free_array(int_array);
		free(line);
		line = get_next_line(fd);
		position.y++;
	}
}
