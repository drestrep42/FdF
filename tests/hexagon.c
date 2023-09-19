#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

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
	int radius = 250; // Adjust the radius as needed
	int color = 0x0000FF; // Hexagon color
	int	i;

	i = 0;
	while(i < 360)
	{
		float angle1 = M_PI / 180 * i;
		float angle2 = M_PI / 180 * (i + 60);
		int x1 = centerX + radius * cos(angle1);
		int y1 = centerY + radius * sin(angle1);
		int x2 = centerX + radius * cos(angle2);
		int y2 = centerY + radius * sin(angle2);
		draw_line(mlx_connection, mlx_window, x1, y1, x2, y2, color);
		i += 60;
	}
	
}

int main()
{
	void *mlx_connection;
	void *mlx_window;

	// Initialize mlx
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "HEXAGON");

	// Call the function to draw the hexagon
	draw_hexagon(mlx_connection, mlx_window);

	// Enter the mlx event loop
	mlx_loop(mlx_connection);

	return 0;
}
