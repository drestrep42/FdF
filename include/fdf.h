/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:06:34 by drestrep          #+#    #+#             */
/*   Updated: 2024/04/18 18:05:14 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./struct.h"
# include "./define.h"
# include "../minilibx/mlx.h"
# include "../libft/include/ft_printf/ft_printf.h"
# include "../libft/include/get_next_line/get_next_line.h"
# include "../libft/include/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>

//	PROGRAM INITIALIZER
t_img		img_init(void *mlx_ptr);
void		fdf_init(t_fdf *fdf);
void		map_init(t_map *map);
void		points_init(t_map *map, int fd);

//	PARSE
void		parsing(t_map *map, int fd);
int			count_numbers(char *line);
void		check_hex_color(char *hex, char *line);
void		check_spaces(char *line);
void		free_array(char **ints);

//	COLOR GRADIENT
int			interpolate(int color1, int color2, float t);

//	DRAW MAP
void		draw_line(t_map map, t_img img, t_vector vector);
void		draw_map(t_fdf *fdf, t_map map);
void		draw_y_lines(t_map map, t_img img);
void		draw_x_lines(t_map map, t_img img);
void		my_pixel_put(t_img *img, int x, int y, int color);

//	ROTATION MATRICES
t_points	rotation_matrices(t_points point);
double		deg_to_rad(double alpha);

//	ERROR MANAGEMENT
void		empty_map(void);
void		usage_error(void);
void		parsing_error(char *error, char *line);

//	KEY HOOKS
int			key_hooks(int keysym, t_fdf *fdf);
void		blackscreen(t_img img);
int			close_win(t_fdf fdf);
void		color_map(int keysym, t_map *map);
void		change_color(t_map *map, int color);
int			events(int keysym, t_fdf *fdf);
void		move_map_iso(int keysym, t_map *map);
void		move_map_pararell(int keysym, t_map *map);

//	MOUSE HOOKS
int			mouse_hooks(int button, int x, int y, t_fdf *fdf);
void		zoom(int button, t_map *map);

#endif
