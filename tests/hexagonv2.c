#include "../libmlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct {
    int x;
    int y;
} Point;

void draw_line(void *mlx_connection, void *mlx_window, Point p1, Point p2, int color)
{
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = p1.x < p2.x ? 1 : -1;
    int sy = p1.y < p2.y ? 1 : -1;
    int err = dx - dy;
    int x = p1.x;
    int y = p1.y;

    while (1)
	{
        mlx_pixel_put(mlx_connection, mlx_window, x, y, color);
        if (x == p2.x && y == p2.y) break;
        int e2 = 2 * err;
        if (e2 > -dy)
		{
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y += sy;
        }
    }
}

void draw_hexagon(void *mlx_connection, void *mlx_window)
{
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int radius = 100; // Adjust the radius as needed
    int color = 0x0000FF; // Hexagon color

    Point vertices[6];

    for (int i = 0; i < 6; i++)
	{
        float angle = 2.0 * M_PI * i / 6.0;
        vertices[i].x = centerX + radius * cos(angle);
        vertices[i].y = centerY + radius * sin(angle);
    }

    // Draw the edges of the hexagon
    for (int i = 0; i < 6; i++) 
	{
        draw_line(mlx_connection, mlx_window, vertices[i], vertices[(i + 1) % 6], color);
    }

   /*  // Fill the hexagon
    for (int y = centerY - radius; y <= centerY + radius; y++)
	{
        for (int x = centerX - radius; x <= centerX + radius; x++)
		{
            int inside = 0;
            for (int i = 0; i < 6; i++)
			{
                int j = (i + 1) % 6;
                if ((vertices[i].y > y) != (vertices[j].y > y) &&
                    x < (vertices[j].x - vertices[i].x) * (y - vertices[i].y) / (vertices[j].y - vertices[i].y) + vertices[i].x)
                    inside = !inside;
            }
            if (inside)
                mlx_pixel_put(mlx_connection, mlx_window, x, y, color);
        }
    } */
}

int main() {
    void *mlx_connection;
    void *mlx_window;

    // Initialize mlx
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Filled Hexagon");

    // Call the function to draw the filled hexagon
    draw_hexagon(mlx_connection, mlx_window);

    // Enter the mlx event loop (you may need to add an event loop for your specific platform)
    mlx_loop(mlx_connection);

    return 0;
}

