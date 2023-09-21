/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:24:27 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/21 18:31:19 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SIDE_LEN 1000

typedef unsigned char	byte;

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
	int  color;
	t_img img;
} 		t_mlx_data;

enum
{
	ON_KEYPRESS = 2,
	ON_KEYREALEASE = 3,
	ON_MOUSECLICK = 4,
	ON_MOUSEREALEASE = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/* void	my_my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->img_pixel_ptr)) = color;
} */

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_pixel_ptr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	render_next_frame(t_mlx_data data)
{
	
	return (0);
}

void	move_image(t_mlx_data *data, int letter)
{
	int	x;
	int	y;

	
}

int	wasd(int keysym, t_mlx_data *data)
{
	if (keysym == 13) // W
			move_image(data, keysym);
	if (keysym == 0) // A
			move_image(data, keysym);
	if (keysym == 1) // S
			move_image(data, keysym);
	if (keysym == 2) // D
			move_image(data, keysym);
	if (keysym == 53) // ESC
		exit(0);
	/* mlx_put_image_to_window(data->mlx_ptr, 
							data->win_ptr, 
							data->img.img_ptr, 
							0, 0); */
	return (0);
}

int main(void)
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
	//draw_circle(&data, SIDE_LEN/2, SIDE_LEN/2, 100);
	mlx_loop_hook(data.win_ptr, draw_circle(&data, SIDE_LEN/2, SIDE_LEN/2, 100), &data);
	mlx_loop(data.mlx_ptr);
}
