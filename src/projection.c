/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:05:40 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/29 21:07:18 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_projection(t_fdf fdf)
{
	float	x;
	float	y;
	float	z;
	float	angle;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	angle = ft_toradian(fdf->isoangle);
	vector->x = (x + y) * cosf(angle);
	vector->y = -z + (x - y) * sinf(angle);

}