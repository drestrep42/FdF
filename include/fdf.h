/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:06:34 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 16:40:30 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./struct.h"
# include "../libmlx/mlx.h"
# include "../libft/include/ft_printf/ft_printf.h"
# include "../libft/include/get_next_line/get_next_line.h"
# include "../libft/include/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>

# define ERROR_USAGE				"Correct use: ./fdf map_name.fdf\n"
# define WRONGLY_DEFINED_COLOR		"Hexadecimal color not correctly defined\n"
# define WRONGLY_DEFINED_NUMBER		"Number is not correctly defined\n"
# define WRONG_AMOUNT_OF_NUMBERS	"Wrong amount of numbers\n"

# define WIDTH 			1000
# define HEIGHT			1000

# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define BLACK			0x000000
# define WHITE			0xFFFFFF

# define R				15
# define G				5
# define B				11

# define I				34
# define P				35

# define KEY_DOWN		2

# define ENTER			36

# define LK				123
# define RK				124
# define DK				125
# define UK				126
# define A				0
# define W				13
# define S				1
# define D				2

# define PLUS			69
# define MINUS 			78
# define CLOSE_WINDOW 	17
# define ESC 			53

//	PARSE
void		parsing(t_map *map, int fd);
void		free_array(char **ints);

//	PROGRAM INITIALIZER
void		map_init(t_map *map);
t_fdf		fdf_init(void);
t_img		img_init(void *mlx_ptr);
void		points_init(t_map *map, int fd);

//	SET PROJECTIONS
t_points	set_projection(t_points point);

//	COLOR GRADIENT
int			interpolate(int color1, int color2, float t);

//	DRAW MAP
void		bres(t_map map, t_vector vector);
void		draw_map(t_map map);
void		draw_y_lines(t_map map);
void		draw_x_lines(t_map map);
void		my_pixel_put(t_img *img, int x, int y, int color);

//	ROTATION MATRICES
t_points	rotation_matrices(t_points point);
double		deg_to_rad(double alpha);

//	ERROR MANAGEMENT
void		usage_error(void);
void		parsing_error(char *error, char *line);

//	KEY HOOKS
void		blackscreen(t_map map);

int			key_hooks(int keysym, t_fdf *fdf);

int			close_win(t_fdf fdf);

void		color_map(int keysym, t_map *map);
void		change_color(t_map *map, int color);

int			events(int keysym, t_fdf *fdf);
void		move_map_iso(int keysym, t_map *map);
void		move_map_pararell(int keysym, t_map *map);


//	MOUSE HOOKS
void		rotate_map(t_points *point);

#endif
