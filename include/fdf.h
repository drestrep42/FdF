/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:06:34 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/21 16:52:57 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libmlx/mlx.h"
#include "../libft/include/ft_printf/ft_printf.h"
#include "../libft/include/get_next_line/get_next_line.h"
#include "../libft/include/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>

# define ERROR_USAGE "Correct use: ./fdf map\n"
# define INVALID MAP "Invalid map"

# define WIDTH 1000
# define HEIGHT 1000

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define YELLOW	0x00FFFF00

typedef struct s_points
{
	int			x;
	int			y;
	int			z;
	int			x0;
	int			xf;
	int			y0;
	int			yf;
	int			dx;
	int			dy;
	int			color;
}				t_points;

typedef struct s_img
{
	void		*img_ptr;
	char		*img_pixel_ptr;
	int			line_length;
	int			endian;
	int			bpp;
}				t_img;

typedef struct s_vector
{
	float		x0;
	float		xf;
	float		y0;
	float		yf;
	int			dx;
	int			dy;
}				t_vector;

typedef struct s_map
{
	int			width;
	int			height;
	int			x_nbrs;
	int			y_nbrs;
	int			tile_size;
	t_points	points;
	t_points	**coord;
	t_vector	vector;
	t_img		img;
}				t_map;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
}				t_fdf;

// PARSE
t_map	read_map(t_map map, int fd);
void	free_array(char **ints);

// PROGRAM INITIALIZER
t_map	initialize_values(t_map map);
t_fdf	fdf_init(void);
t_img	img_init(void *mlx_ptr);
void	get_z_values(t_map *map, int fd);

// ERROR CONTROL
void	malloc_error(void);

// SET PROJECTIONS
void	set_projection(t_points point);

// EVENTS
void	key_handle(int keysym, t_fdf fdf);
int		handle_input(int keysym, t_fdf *fdf);
int		close_win(t_fdf *fdf);

// BRESENHAM'S ALGORITHM
void		draw_line(t_fdf fdf, t_points points);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		bigger_than_1(t_fdf fdf, t_points points, int abs_dx, int abs_dy);
void		smaller_than_1(t_fdf fdf, t_points points, int abs_dx, int abs_dy);

// DRAW MAP
void	draw_map(t_fdf fdf);

// MOVE_MAP
void	move_map(t_fdf fdf, int keysym);

// RENDER NEXT FRAME
void	render_next_frame(t_fdf fdf, t_img img);

#endif
