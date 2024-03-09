/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:04:45 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/09 22:16:12 by drestrep         ###   ########.fr       */
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

char	*get_string(char *s1, char start, char end)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != start && s1[i] != '\0' && s1[i] != '\n')
		i++;
	if (s1[i] == start)
	{
		while (s1[i] != end && s1[i] != '\0' && s1[i] != '\n')
		{
			i++;
			j++;
		}
		s2 = malloc((j + 2) * sizeof(char));
		i -= j;
		j = 0;
		while (s1[i] != end && s1[i] != '\0' && s1[i] != '\n')
			s2[j++] = s1[i++];
		s2[j] = s1[i];
		s2[j + 1] = '\0';
		return (s2);
	}
	return (NULL);
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
			hex = get_string(line + counter, '0', ' ');
			if (check_hex_color(hex) == -1)
			{
				free(hex);
				error(WRONGLY_DEFINED_COLOR, line);
			}
			counter += ft_strlen(hex);
			free(hex);
		}
		else if (!ft_isdigit(line[counter]) \
		&& line[counter] != ' ' && line[counter] != '-')
			error(WRONGLY_DEFINED_NUMBER, line);
		if (line[counter] == '\0')
			return (number_of_numbers);
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
			error(WRONGLY_DEFINED_NUMBER, line);
		counter++;
	}
}

t_map	parsing(t_map map, int fd)
{
	char	*line;
	int		numbers;

	map.y_nbrs = 0;
	line = get_next_line(fd);
	numbers = count_numbers(line);
	while (line)
	{
		check_spaces(line);
		map.x_nbrs = count_numbers(line);
		if (map.x_nbrs != numbers)
			error(WRONG_AMOUNT_OF_NUMBERS, line);
		map.y_nbrs++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}
