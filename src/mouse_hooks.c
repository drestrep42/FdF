/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:09:32 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 22:43:24 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(int button, t_map *map)
{
	if (button == ON_MOUSEUP)
		map->zoom += 1;
	if (button == ON_MOUSEDOWN)
		map->zoom -= 1;
}

int	mouse_hooks(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	blackscreen(fdf->img);
	if (button == ON_MOUSEUP || button == ON_MOUSEDOWN)
		zoom(button, &fdf->map);
	draw_map(fdf, fdf->map);
	return (0);
}
