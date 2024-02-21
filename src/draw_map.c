/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:29 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/21 17:01:06 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_yf(t_fdf fdf, int y_nbrs, int caller)
{
	int	y;

	y = fdf.map.points.y0;
	while (y_nbrs > 0)
	{
		fdf.map.points.yf = fdf.map.points.y0;
		if (caller == 1)
			draw_line(fdf, fdf.map.points);
		if (fdf.map.y_nbrs > fdf.map.x_nbrs)
			fdf.map.points.y0 += fdf.map.height / fdf.map.y_nbrs;
		else
			fdf.map.points.y0 += fdf.map.height / fdf.map.x_nbrs;
		y_nbrs--;
	}
	fdf.map.points.y0 = y;
	return (fdf.map.points.yf);
}

void	draw_map(t_fdf fdf)
{
	int	x;
	int	x_nbrs;
	int	y_nbrs;

	x = fdf.map.points.x0;
	x_nbrs = fdf.map.x_nbrs;
	y_nbrs = fdf.map.y_nbrs;
	if (x_nbrs == y_nbrs)
	{
		fdf.map.x_nbrs--;
		fdf.map.y_nbrs--;
	}
	while (x_nbrs > 0)
	{
		fdf.map.points.yf = get_yf(fdf, y_nbrs, 0);
		fdf.map.points.xf = fdf.map.points.x0;
		//set_projection(fdf.map.points);
		/* ft_printf("x0: %d xf: %d y0: %d yf: %d\n", fdf.map.points.x0, fdf.map.points.xf, fdf.map.points.y0, fdf.map.points.yf);
		exit(0); */
		fdf.map.points.color = RED;
		ft_printf("%d\n", fdf.map.points.color);
		draw_line(fdf, fdf.map.points);
		if (fdf.map.y_nbrs > fdf.map.x_nbrs)
			fdf.map.points.x0 += fdf.map.width / fdf.map.y_nbrs;
		else
			fdf.map.points.x0 += fdf.map.width / fdf.map.x_nbrs;
		x_nbrs--;
	}
	/* ft_printf("%d\n", fdf.map.points.color);
	exit(0); */
	fdf.map.points.x0 = x;
	fdf.map.points.yf = get_yf(fdf, y_nbrs, 1);
}
