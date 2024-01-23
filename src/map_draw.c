/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:36:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/23 18:54:17 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	deg_to_rad(int alpha)
{
	return (alpha * M_PI / 180);
}

int	get_3d_point(t_points points, double alpha_rad, char caller)
{
	int	point;

	if (caller == 'u')
	{
		point = points.x0 * cos(alpha_rad)
		+ points.y0 * cos(alpha_rad + deg_to_rad(120))
		+ points.z * cos(alpha_rad - deg_to_rad(120));	
	}
	else if (caller == 'v')
	{
		point = points.x0 * sin(alpha_rad)
		+ points.y0 * sin(alpha_rad + deg_to_rad(120))
		+ points.z * sin(alpha_rad - deg_to_rad(120));
	}
}

void	def_draw_map(t_fdf fdf)
{
	double	alpha_rad;
	int		u;
	int		v;

	alpha_rad = deg_to_rad(30);
	u = get_3d_point(fdf.map.points, alpha_rad, 'u');
	v = get_3d_point(fdf.map.points, alpha_rad, 'v');
	
}
