/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:54:16 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/12 16:05:13 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_img	img_init(void *mlx_ptr)
{
	t_img	img;

	ft_bzero(&img, sizeof(img));
	img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.img_pixel_ptr = mlx_get_data_addr(img.img_ptr,
			&img.bpp,
			&img.line_length,
			&img.endian);
	return (img);
}

t_fdf	fdf_init(void)
{
	t_fdf	fdf;

	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, "FdF");
	if (!fdf.win_ptr)
	{
		free (fdf.mlx_ptr);
		exit(1);
	}
	fdf.map.img = img_init(fdf.mlx_ptr);
	return (fdf);
}
