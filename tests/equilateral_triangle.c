#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

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

int main()
{
	void *mlx_connection;
	void *mlx_window;

	// Initialize mlx
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Equilateral Triangle");

	// Call the function to draw the equilateral triangle
	draw_equilateral_triangle(mlx_connection, mlx_window);

	// Enter the mlx event loop
	mlx_loop(mlx_connection);

	return 0;
}
