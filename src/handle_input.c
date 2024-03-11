/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:29:20 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/11 23:21:32 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* void	free_coord(t_map map)
{
	int	y;

	y = 0;
	while (y < map.y_nbrs)
	{
		free(map.coord[y]);
		y++;
	}
	free(map.coord);
} */

void	ft_free(t_fdf fdf)
{
	int	y;

	y = 0;
	mlx_destroy_image(fdf.mlx_ptr, fdf.map.img.img_ptr),
	mlx_destroy_window(fdf.mlx_ptr, fdf.win_ptr);
	ft_printf("Se supone que llega aquí\n");
	while (y < fdf.map.y_nbrs)
	{
		free(fdf.map.coord[y]);
		y++;
	}
}

int	close_win(t_fdf fdf)
{
	ft_free(fdf);
	exit(0);
}

void	key_handle(int keysym, t_fdf fdf)
{
	ft_printf("The key %d has been pressed\n", keysym);
	if (keysym == 36)
		draw_map(fdf.map);
}

int	handle_input(int keysym, t_fdf *fdf)
{
	key_handle(keysym, *fdf);
	if (keysym == 53)
	{
		ft_printf("ESC has been pressed\n");
		close_win(*fdf);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->map.img.img_ptr, 0, 0);
	return (0);
}
