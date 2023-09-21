/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:47:14 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/22 00:22:16 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		malloc_error(&fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FdF");
	if (!fdf->win_ptr)
	{
		free (fdf->mlx_ptr); // ???
		malloc_error(&fdf);
	}
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	if (!fdf->img.img_ptr)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free (fdf->mlx_ptr); // ???
		malloc_error(&fdf);
	}
	fdf->img.img_pixel_ptr = mlx_get_data_addr(fdf->img.img_ptr, 
												&fdf->img.bpp, 
												&fdf->img.line_length, 
												&fdf->img.endian);
}
