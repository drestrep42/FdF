/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:20:44 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/22 13:54:27 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	deg_to_rad(double alpha)
{
	return (alpha * M_PI / 180);
}

t_points rotate_z_axis(t_points point)
{
	t_points	new_point;
	double		alpha;

	alpha = deg_to_rad(45);
	new_point.x = point.x * cos(alpha) - point.y * sin(alpha);
	new_point.y = point.x * sin(alpha) + point.y * cos(alpha);
	new_point.z = point.z;
	return (new_point);
}

t_points	rotate_x_axis(t_points point)
{
	t_points	new_point;
	double		alpha;

	alpha = deg_to_rad(35.264);
	new_point.x = point.x;
	new_point.y = point.y * cos(alpha) - point.z * sin(alpha);
	new_point.z = point.y * sin(alpha) + point.z * cos(alpha);
	return (new_point);
}

t_points	rotation_matrices(t_points point)
{
	int	color;

	color = point.color;
	point = rotate_z_axis(point);
	point = rotate_x_axis(point);
	point.x += WIDTH / 2;
	point.color = color;
	return (point);
}
