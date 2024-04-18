/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:52:53 by drestrep          #+#    #+#             */
/*   Updated: 2024/04/18 18:05:02 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	empty_map(void)
{
	ft_printf(EMPTY);
	exit(1);
}

void	usage_error(void)
{
	ft_printf(ERROR_USAGE);
	exit(1);
}

void	parsing_error(char *error, char *line)
{
	free(line);
	ft_printf("%s", error);
	exit(1);
}
