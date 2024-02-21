/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:29:20 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/21 16:44:36 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(t_fdf *fdf)
{
	(void)fdf;
	exit(0);
}

void	key_handle(int keysym, t_fdf fdf)
{
	ft_printf("The key %d has been pressed\n", keysym);
	if (keysym == 2)
		draw_line(fdf, fdf.map.points);
	if (keysym == 36)
		draw_map(fdf);
	/* if (keysym == 123 || keysym == 124 || keysym == 125 || keysym == 126)
		move_map(fdf, keysym); */
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
