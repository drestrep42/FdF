/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:29:20 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/09 17:49:23 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free(t_fdf fdf)
{
	mlx_destroy_image(fdf.mlx_ptr, fdf.map.img.img_ptr),
	mlx_destroy_window(fdf.mlx_ptr, fdf.win_ptr);
	free(fdf.map.coord);
}

int	close_win(t_fdf *fdf)
{
	ft_free(*fdf);
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
		close_win(fdf);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->map.img.img_ptr, 0, 0);
	return (0);
}
