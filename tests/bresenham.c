/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:04:24 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/21 21:06:17 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

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
	int  color;
	t_img img;
} 		t_mlx_data;

/* void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_pixel_ptr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
} */

/* void	draw_square(t_mlx_data *data)
{
	int		x;
	int		y;

	y = SIDE_LEN * 0.1;
	while (++y < SIDE_LEN * 0.9)
	{
		x = SIDE_LEN * 0.1;
		while (++x < SIDE_LEN * 0.9)
			my_pixel_put(&data->img, x, y, data->color);
	}
} */

/* void draw_square(t_mlx_data *data)
{
	int x;
	int y;

	for (y = SIDE_LEN * 0.4; y < SIDE_LEN * 0.6; y++)
	{
		for (x = SIDE_LEN * 0.4; x < SIDE_LEN * 0.6; x++)
		{
			my_pixel_put(&data->img, x, y, data->color);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, 
							data->win_ptr, 
							data->img.img_ptr, 
							0, 0);
} */

/* void	draw_square(t_mlx_data *data, int point1, int point2)
{

} */

/* void	small_slope(t_mlx_data *data, int slope, int x1, int y1, int x2, int y2)
{
	int		offset;
	float	threshold;
	int		adjust;

	offset = 1;
	threshold = 0.5;
	adjust = (slope >= 0) ? 1 : -1;
	slope = abs(slope);
}

void	draw_line(t_mlx_data *data, int x1, int y1, int x2, int y2)
{
	int	slope;
	int	rise;
	int	run;

	rise = y2 - y1;
	run = x2 - x1;
	if (run == 0)
		printf("Lo hacemos después\n");
	else
	{
		slope = rise / run;
		if (slope >= -1 && slope <= 1)
			small_slope (&data);
	}
} */

void my_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->img_pixel_ptr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_line(t_mlx_data *data, int x1, int y1, int x2, int y2)
{
	int	dx = abs(x2 - x1);
	int	dy = abs(y2 - y1);
	int	sx = x1 < x2 ? 1 : -1;
	int	sy = y1 < y2 ? 1 : -1;
	int	err = dx - dy;
	int	e2;

	while (1)
	{
		my_pixel_put(&data->img, x1, y1, data->color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_hexagon(t_mlx_data *data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	i;

	i = 0;
	while (i < 360)
	{
		x1 = SIDE_LEN / 2 + 200 * cos(M_PI / 180 * i);
		y1 = SIDE_LEN / 2 + 200 * sin(M_PI / 180 * i);
		x2 = SIDE_LEN / 2 + 200 * cos(M_PI / 180 * (i + 60));
		y2 = SIDE_LEN / 2 + 200 * sin(M_PI / 180 * (i + 60));
		i += 60;
	}
}

int	f(int keysym, t_mlx_data *data)
{
	if (keysym == 53)
		exit(0);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

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
	draw_hexagon(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, f, &data);
	mlx_loop(data.mlx_ptr);
}
