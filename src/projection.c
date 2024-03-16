/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:05:40 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/14 17:26:59 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_points	set_projection(t_points point)
{
	float	angle;
	float	x;
	float	y;
	float	z;

	x = point.x;
	y = point.y;
	z = point.z;
	angle = deg_to_rad(30);
	point.x = (x + y) * cosf(angle);
	point.y = -z + (x - y) * sinf(angle);
	return (point);
}
