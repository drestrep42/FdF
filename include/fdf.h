/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:06:34 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/12 17:02:24 by drestrep         ###   ########.fr       */
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

# define ERROR_USAGE "Correct use: ./fdf map_name.fdf\n"
# define WRONGLY_DEFINED_COLOR "Hexadecimal color is not correctly defined\n"
# define WRONGLY_DEFINED_NUMBER "Number is not correctly defined\n"
# define WRONG_AMOUNT_OF_NUMBERS "Wrong amount of numbers\n"

# define WIDTH 1000
# define HEIGHT 1000

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

//	PARSE
t_map		parsing(t_map map, int fd);
void		free_array(char **ints);

//	PROGRAM INITIALIZER
t_map		map_init(t_map map);
t_fdf		fdf_init(void);
t_img		img_init(void *mlx_ptr);
t_points	**points_init(t_map map, int fd);

//	SET PROJECTIONS
t_points	set_projection(t_points point);

//	EVENTS
void		key_handle(int keysym, t_fdf fdf);
int			handle_input(int keysym, t_fdf *fdf);
int			close_win(t_fdf fdf);

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
void usage_error(void);
void parsing_error(char *error, char *line);
void ft_free(t_fdf fdf);


#endif
