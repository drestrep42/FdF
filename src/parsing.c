/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:04:45 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/14 17:22:54 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_hex_color(char *line)
{
	int		counter;

	counter = 0;
	if (ft_strlen(line) < 4 || ft_strlen(line) > 9)
		return (-1);
	if (line[0] != '0' || line[1] != 'x')
		return (-1);
	while (counter < ft_strlen(line) - 1)
	{
		if (!ft_isalnum(line[counter]))
			return (-1);
		counter++;
	}
	return (1);
}

int	count_numbers(char *line)
{
	char	*hex;
	int		counter;
	int		number_of_numbers;

	counter = 0;
	number_of_numbers = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
	{
		if (line[counter] == ',')
		{
			hex = ft_get_string(line + counter, '0', ' ');
			if (check_hex_color(hex) == -1)
				parsing_error(WRONGLY_DEFINED_COLOR, line);
			counter += ft_strlen(hex);
			free(hex);
		}
		else if (!ft_isdigit(line[counter]) \
		&& line[counter] != ' ' && line[counter] != '-')
			parsing_error(WRONGLY_DEFINED_NUMBER, line);
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
		if (ft_issign(line[counter]) && line[counter - 1] != ' ')
			parsing_error(WRONGLY_DEFINED_NUMBER, line);
		counter++;
	}
}

void	parsing(t_map *map, int fd)
{
	char	*line;
	int		numbers;

	map->y_nbrs = 0;
	line = get_next_line(fd);
	numbers = count_numbers(line);
	while (line)
	{
		check_spaces(line);
		map->x_nbrs = count_numbers(line);
		if (map->x_nbrs != numbers)
			parsing_error(WRONG_AMOUNT_OF_NUMBERS, line);
		map->y_nbrs++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
