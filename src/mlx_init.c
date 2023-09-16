/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:55:07 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/16 08:37:25 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

/* int main ()
{
	int		y;
	int		x;
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection,
								WIDTH,
								HEIGHT,
								"Ñóà?");
	y = HEIGHT * 0.1;
	while (++y < HEIGHT * 0.9)
	{
		x = WIDTH * 0.1;
		while (++x < WIDTH * 0.9)
		{
			mlx_pixel_put(mlx_connection, mlx_window,
							x,
							y,
							0x0000FF);
		}
	}
	mlx_loop(mlx_connection);
} */

void draw_equilateral_triangle(void *mlx_connection, void *mlx_window)
{
	int	x;
	int	y;
	int	i;

	y = HEIGHT / 3;
	i = 0;
	while (++y < (2 * HEIGHT) / 3)
	{
		x = WIDTH / 2 - i;
		while (++x < WIDTH / 2 + i)
			mlx_pixel_put(mlx_connection, mlx_window, x, y, 0x0000FF);
		i++;
	}
}

void draw_line(void *mlx_connection, void *mlx_window, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        mlx_pixel_put(mlx_connection, mlx_window, x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        e2 = err;

        if (e2 > -dx)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dy)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_hexagon(void *mlx_connection, void *mlx_window)
{
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int radius = 100; // Adjust the radius as needed
    int color = 0x0000FF; // Hexagon color

    for (int i = 0; i < 360; i += 60)
    {
        float angle1 = M_PI / 180 * i;
        float angle2 = M_PI / 180 * (i + 60);

        int x1 = centerX + radius * cos(angle1);
        int y1 = centerY + radius * sin(angle1);
        int x2 = centerX + radius * cos(angle2);
        int y2 = centerY + radius * sin(angle2);

        // Draw a line from (x1, y1) to (x2, y2)
        draw_line(mlx_connection, mlx_window, x1, y1, x2, y2, color);
    }
}

int main()
{
    void *mlx_connection;
    void *mlx_window;

    // Initialize mlx
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Equilateral Triangle");

    // Call the function to draw the equilateral triangle
    //draw_equilateral_triangle(mlx_connection, mlx_window);
    draw_hexagon(mlx_connection, mlx_window);

    // Enter the mlx event loop (you may need to add an event loop for your specific platform)
    mlx_loop(mlx_connection);

    return 0;
}





/* void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_pixel_put(mlx, mlx_win, WIDTH, HEIGHT, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

