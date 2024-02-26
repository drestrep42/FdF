/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:53:51 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/25 22:17:09 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	assign_coord_values(t_map map, t_points position, char **int_array)
{
	char	*hex_value;

	while (position.x < map.x_nbrs)
	{
		map.coord[position.y][position.x].x = position.x;
		map.coord[position.y][position.x].y = position.y;
		/* if (position.x == 19)
		{
			//ft_printf("x: %d, y: %d\n", map.coord[position.y][position.x].x, map.coord[position.y][position.x].y);
			ft_printf("%s\n", int_array[position.x]);
			exit(0);
		} */
		if (!ft_strchr(int_array[position.x], ','))
		{
			map.coord[position.y][position.x].z \
			= ft_atoi(int_array[position.x]);
			map.coord[position.y][position.x].color = RED;
			//ft_printf("%d\n", map.coord[position.y][position.x].color);
		}
		else
		{
			//hex_value = ft_strchr(ft_strchr(int_array[position.x], ','), '0');
			hex_value = ft_strchr(int_array[position.x], ',');
			ft_printf("%s\neeeeeee", hex_value);
			exit(0);
			map.coord[position.y][position.x].z \
			= ft_atoi(ft_revstrchr(int_array[position.x], ','));
			map.coord[position.y][position.x].color = ft_atoi(hex_value);
		}
		position.x++;
	}
}

void	printarrays(char **arrays)
{

	while (*arrays && arrays)
	{
		ft_printf("%s\n", *arrays);
		arrays++;
	}
	exit(0);
}

t_points	**points_init(t_map map, int fd)
{
	t_points	position;
	char		*line;
	char		**int_array;

	position.y = 0;
	line = get_next_line(fd); 
	map.coord = ft_calloc(map.y_nbrs + 1, sizeof(t_points *));
	while (position.y < map.y_nbrs)
	{
		map.coord[position.y] = ft_calloc(map.x_nbrs + 1, sizeof(t_points));
		int_array = ft_split(line, ' ');
		assign_coord_values(map, position, int_array);
		free_array(int_array);
		free(line);
		line = get_next_line(fd);
		position.y++;
	}
	//ft_printf("%d\n", map.coord[3][1].z);
	/* ft_printf("%d\n", map.coord[0][0].color);
	exit(0); */
	free(line);
	return (map.coord);
}
