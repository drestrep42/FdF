/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:55:07 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/24 02:27:50 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 800

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

int	close(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
	return (0);
}

int	key_pressed(int keysym, t_mlx_data *data)
{
	if (keysym == 53)
	{
		printf("The key pressed is: %d (ESC), terminating program.\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	printf("The key pressed is: %d\n", keysym);
	return (0);
}


int	key_released(int keysym, t_mlx_data *data)
{
	printf("The key lifted is: %d\n", keysym);
	return (0);
}

int	change_color(t_mlx_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH/2, HEIGHT/2, data->color, "PUMP IT");
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
} 

int	button_pressed(int button, int x, int y, t_mlx_data *data)
{
	printf("The button %d has been pressed in X: %d Y: %d\n", button, x, y);
	return (0);
}

int	mouse_coordinates(int x, int y, t_mlx_data *data)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        printf("X: %d Y: %d\n", x, y);
    }
    return (0);
}

int	mouse_in_n_out(int x, int y, t_mlx_data *data)
{
	static int i;
	static int j;

	if (!i && !j)
	{
		i = 0;
		j = 0;
	}
	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
		i = 1;
	if (i == 1 && j == 0)
	{
		printf("Hello there!\n");
		j = 1;
	}
	if ((x < 0 || x > WIDTH || y < 0 || y > HEIGHT))
		i = 2;
	if (i == 2 && j == 1)
	{
		printf("Goodbye!\n");
		x = 0;
		j = 0;
	}
	return (0);
}

int main(void)
{
	t_mlx_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FdF");
	data.color = 0x00FF00;
	mlx_hook(data.win_ptr, 2, 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 6, 0, mouse_in_n_out, &data);
	mlx_hook(data.win_ptr, 17, 0, close, &data);
	//mlx_hook(data.win_ptr, 6, 0, mouse_coordinates, &data);
	mlx_key_hook(data.win_ptr, key_released, &data);
	mlx_mouse_hook(data.win_ptr, button_pressed, &data);
	mlx_loop_hook(data.mlx_ptr, change_color, &data);
	
	//mlx_pixel_put(data.mlx_ptr, data.win_ptr, WIDTH, HEIGHT, 0x00FF0000);
	mlx_loop(data.mlx_ptr);
}

