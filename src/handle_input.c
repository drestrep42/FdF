/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:29:20 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/15 16:57:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(t_fdf fdf)
{
	(void)fdf;
	exit(0);
}


/* void	move_map(t_fdf fdf, t_map map, int keysym)
{
	(void)fdf;
	if (keysym == LEFT_KEY)
	{
		map.start_point.x -= 50;
		map.end_point.x -= 50;
		draw_map(map);
	}
	if (keysym == RIGHT_KEY)
	{
		map.start_point.x += 50;
		map.end_point.x += 50;
		draw_map(map);
	}
} */

/* int	handle_input(int keysym, t_fdf *fdf)
{
	if (keysym == ENTER)
		draw_map(fdf->map);
	if (keysym >= 123 && keysym <= 126)
		move_map(*fdf, fdf->map, keysym);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->map.img.img_ptr, 0, 0);
	return (0);
} */
