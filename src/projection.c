/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:05:40 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/21 16:43:03 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	deg_to_rad(int alpha)
{
	return (alpha * M_PI / 180);
}

void	set_projection(t_points point)
{
	float	x;
	float	y;
	float	z;
	float	angle;

	x = point.x0;
	y = point.y0;
	z = point.z;
	angle = deg_to_rad(30);
	point.x = (x + y) * cosf(angle);
	point.y = -z + (x - y) * sinf(angle);
}
