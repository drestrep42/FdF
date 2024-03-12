/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:52:53 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/12 16:17:26 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
