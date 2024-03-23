/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:55:13 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 15:52:12 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_z(t_points *point)
{
	double alpha;

	alpha = deg_to_rad(45);
	point->x = point->x * cos(alpha) - point->y * sin(alpha);
	point->y = point->x * sin(alpha) + point->y * cos(alpha);
	point->z = point->z;
}

void	rotate_x(t_points *point)
{
	double alpha;

	alpha = deg_to_rad(35.264);
	point->x = point->x;
	point->y = point->y * cos(alpha) - point->z * sin(alpha);
	point->z = point->y * sin(alpha) + point->z * cos(alpha);
}
