/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:24:08 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/25 21:04:09 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_points	change_values_0(t_vector vector, t_points point, int p, int t)
{
	if (vector.dx < 0)
		point.x--;
	else
		point.x++;
	if (p >= 0)
	{
		p = p + 2 * (vector.dy - vector.dx);
		if (vector.dy < 0)
			point.y--;
		else
			point.y++;
	}
	else
		p = p + 2 * vector.dy;
	//if (vector.start_point.color == 0)
	//	vector.start_point.color = RED;
	//ft_printf("Start point color:%d\nEnd point color: %d\n", vector.start_point.color, vector.end_point.color);
	point.color = vector.start_point.color \
	+ (vector.end_point.color - vector.start_point.color) * t;
	return (point);
}

t_points	change_values_1(t_vector vector, t_points point, int p, int t)
{
	if (vector.dy < 0)
		point.y--;
	else
		point.y++;
	if (p >= 0)
	{
		p = p + 2 * (vector.dx - vector.dy);
		if (vector.dx < 0)
			point.x--;
		else
			point.x++;
	}
	else
		p = p + 2 * vector.dx;
	point.color = vector.start_point.color \
	+ (vector.end_point.color - vector.start_point.color) * t;
	return (point);
}
