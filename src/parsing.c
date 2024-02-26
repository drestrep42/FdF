/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:04:45 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/23 18:59:31 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	hex_color(char *line, int counter)
{
	char	*substr;

	substr = ft_calloc(9, sizeof(char));
	if (line[counter] == ',' && line[counter + 1] == '0'
		&& line[counter + 2] == 'x')
	{
		substr = ft_substr(line, counter + 1, 9);
		counter = 0;
		while (counter < 8)
		{
			if (!ft_isalnum(substr[counter]))
			{
				ft_printf("INVALID_MAP hex number is not alnum\n");
				free(line);
				exit(1);
			}
			counter++;
		}
		return (1);
	}
	ft_printf("INVALID_MAP hex color is not correctly defined\n");
	free(line);
	exit(1);
}

void	check_numbers(char *line)
{
	int	counter;

	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
	{
		if (line[counter] == ',' && hex_color(line, counter))
			counter += 9;
		else if (!ft_isdigit (line[counter]) && line[counter] != ' '
			&& line[counter] != '-')
		{
			//ft_printf("Line number: %d\nCounter: %d\nCurrent char:%c\n", map.y_nbrs, counter, line[counter]);
			ft_printf("INVALID_MAP letra3\n");
			free(line);
			exit(1);
		}
		counter++;
	}
}

int	count_numbers(char *line)
{
	int	counter;
	int	number_of_numbers;

	counter = 0;
	number_of_numbers = 0;
	while (line[counter] != '\0')
	{
		if (line[counter] == ',')
			counter += 9;
		if (ft_isdigit(line[counter]) && !ft_isdigit(line[counter + 1]))
			number_of_numbers++;
		counter++;
	}
	return (number_of_numbers);
}

void	check_spaces(char *line)
{
	int	counter;

	counter = 1;
	while (line[counter] != '\n' && line[counter] != '\0')
	{
		if (line[counter] == '-' && line[counter - 1] != ' ')
		{
			ft_printf("INVALID_MAP espacios\n");
			free(line);
			exit(1);
		}
		counter++;
	}
}

t_map	parsing(t_map map, int fd) 
{
	char	*line;
	int		numbers;
	int		x;

	map.y_nbrs = 0;
	line = get_next_line(fd);
	numbers = count_numbers(line);
	while (line)
	{
		check_spaces(line);
		map.x_nbrs = count_numbers(line);
		if (map.x_nbrs != numbers)
		{
			ft_printf("INVALID_MAP número de elementos\n");
			exit(1);
		}
		x = 0;
		while (x < map.x_nbrs)
		{
			check_numbers(line);
			x++;
		}
		map.y_nbrs++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}
