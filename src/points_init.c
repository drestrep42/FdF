/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:53:51 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/12 22:53:07 by drestrep         ###   ########.fr       */
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

int	hex_to_decimal(char hex)
{
	if (hex >= '0' && hex <= '9')
		return (hex - '0');
	else if (hex >= 'A' && hex <= 'F')
		return (hex - 'A' + 10);
	else if (hex >= 'a' && hex <= 'f')
		return (hex - 'a' + 10);
	else
		return (-1);
}

int	ft_atoi_base(char *str)
{
	int		number;
	int		digit;
	int		i;

	number = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i] != '\0' && str[i] != '\n')
	{
		digit = hex_to_decimal(str[i]);
		if (digit == -1)
		{
			ft_printf("%s wrong hex value, %c", str, str[i]);
			exit(1);
		}
		number = number * 16 + digit;
		i++;
	}
	return (number);
}

void	assign_coord_values(t_map map, t_points position, char **int_array)
{
	char	*hex_value;

	while (position.x < map.x_nbrs)
	{
		map.coord[position.y][position.x].x = position.x;
		map.coord[position.y][position.x].y = position.y;
		map.coord[position.y][position.x].z = \
			ft_atoi(int_array[position.x]) * 10;
		if (!ft_strchr(int_array[position.x], ','))
			map.coord[position.y][position.x].color = BLUE;
		else
		{
			hex_value = ft_strchr(int_array[position.x], ',') + 1;
			map.coord[position.y][position.x].color = ft_atoi_base(hex_value);
		}
		position.x++;
	}
}

t_points	**points_init(t_map map, int fd)
{
	t_points	position;
	char		*line;
	char		**int_array;

	ft_bzero(&position, sizeof(position));
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
	free(line);
	return (map.coord);
}
