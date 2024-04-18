/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:16:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 22:26:21 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	interpolate(int start_color, int end_color, float t)
{
	if (start_color == end_color)
		return (start_color);
	return ((int)start_color + (end_color - start_color) * t);
}
