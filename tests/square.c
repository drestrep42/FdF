#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

void	draw_square(void *mlx_connection, void *mlx_window)
{
	int		x;
	int		y;

	y = HEIGHT * 0.1;
	while (++y < HEIGHT * 0.9)
	{
		x = WIDTH * 0.1;
		while (++x < WIDTH * 0.9)
		{
			mlx_pixel_put(mlx_connection, mlx_window, x, y, 0x0000FF);
		}
	}
}

int main ()
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "SQUARE");
	draw_square(mlx_connection, mlx_window);
	mlx_loop(mlx_connection);
}
