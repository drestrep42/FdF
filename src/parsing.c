/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:04:45 by drestrep          #+#    #+#             */
/*   Updated: 2024/04/18 21:26:42 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	check_hex_color(char *hex, char *line)
{
	int		counter;

	counter = 0;
	if (ft_strlen(hex) < 4 || ft_strlen(hex) > 9)
		parsing_error(WRONGLY_DEFINED_COLOR, line);
	if (hex[0] != '0' || hex[1] != 'x')
		parsing_error(WRONGLY_DEFINED_COLOR, line);
	while (counter < ft_strlen(hex) - 1)
	{
		if (!ft_isalnum(hex[counter++]))
			parsing_error(WRONGLY_DEFINED_COLOR, line);
	}
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
			check_hex_color(hex, line);
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

void	parsing(t_map *map, int fd)
{
	char	*line;
	int		numbers;

	map->y_nbrs = 0;
	line = get_next_line(fd);
	if (!line)
		empty_map();
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
}
