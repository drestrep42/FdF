/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:52:54 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/20 13:31:57 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SIDE_LEN 1000

typedef unsigned char	byte;

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	int  color;
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

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

void	color_screen(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < SIDE_LEN)
	{
		x = 0;
		while (x++ < SIDE_LEN)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
	}
}

int	f(int keysym, t_mlx_data *data)
{
	if (keysym == 15)
		color_screen(data, encode_rgb(255, 0, 0));
	if (keysym == 5)
		color_screen(data, encode_rgb(0, 0xff, 0));
	if (keysym == 11)
		color_screen(data, encode_rgb(0, 0, 0xff));
	return (0);
}

int main(void)
{
	t_mlx_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIDE_LEN, SIDE_LEN, "SLOW");
	data.color = 0x00FF00;

	mlx_key_hook(data.win_ptr, f, &data);
	mlx_loop(data.mlx_ptr);
}