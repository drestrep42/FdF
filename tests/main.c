/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:07:23 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/21 14:02:11 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SIDE_LEN 1000

typedef struct	s_image
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx_data
{
	void  *mlx_ptr;
	void  *win_ptr;
	t_img img;
} 		t_mlx_data;

/* int main(void)
{
	t_mlx_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIDE_LEN, SIDE_LEN, "FAST");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, SIDE_LEN, SIDE_LEN);
	data.img.img_pixel_ptr = mlx_get_data_addr(data.img.img_ptr, 
												&data.img.bpp, 
												&data.img.line_length, 
												&data.img.endian);
	data.color = 0x00FF00;
	mlx_key_hook(data.win_ptr, close, &data);
	mlx_loop(data.mlx_ptr);
} */

/* int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "../images/test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
} */

int	main(void)
{
	t_mlx_data data;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL) {
        fprintf(stderr, "mlx_init failed\n");
        return 1;
    }
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIDE_LEN, SIDE_LEN, "TEST");
	if (data.win_ptr == NULL) {
        fprintf(stderr, "mlx_new_window failed\n");
        return 1;
    }
	data.img.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	if (data.img.img_ptr == NULL) {
        fprintf(stderr, "mlx_xpm_file_to_image failed\n");
        return 1;
    }
	data.img.img_pixel_ptr = mlx_get_data_addr(data.img.img_ptr, 
												&data.img.bpp, 
												&data.img.line_length, 
												&data.img.endian);
	mlx_loop(data.mlx_ptr);
}