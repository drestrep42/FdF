/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:29:20 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/12 22:53:31 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(t_fdf fdf)
{
	(void)fdf;
	exit(0);
}

int	handle_input(int keysym, t_fdf *fdf)
{
	if (keysym == 36)
		draw_map(fdf->map);
	if (keysym == 53)
	{
		ft_printf("ESC has been pressed\n");
		exit(0);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->map.img.img_ptr, 0, 0);
	return (0);
}
