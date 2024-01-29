/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:04:45 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/29 19:53:30 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_is_number(char *line)
{
	int	counter;

	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
	{
		if(!ft_isdigit(line[counter]) && line[counter] != ' ' && line[counter] != '-')
		{
			ft_printf("INVALID_MAP letra\n");
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
		if (ft_isdigit(line[counter]) && !ft_isdigit(line[counter + 1]))
			number_of_numbers++;
		counter++;
	}
	return(number_of_numbers);
}

void	check_spaces(char *line)
{
	int	counter;

	counter = 0;
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

t_map	read_map(t_map map, int fd)
{
	char	*line;
	int		numbers;

	line = get_next_line(fd);
	map.y_nbrs = 0;
	map.x_nbrs = count_numbers(line);
	numbers = map.x_nbrs;	
	while (line != NULL)
	{
		//ft_printf("%s\n", line);
		check_is_number(line);
		check_spaces(line);
		map.x_nbrs = count_numbers(line);
		if (map.x_nbrs != numbers)
		{
			ft_printf("INVALID_MAP número\n");
			free(line);
			exit(1);
		}
		//get_z_values(&map, ft_split(line, ' '));
		map.y_nbrs++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}
