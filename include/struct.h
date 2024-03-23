/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:09:44 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/23 16:46:20 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_bresenham
{
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_bresenham;

typedef struct s_points
{
	int			x;
	int			y;
	int			z;
	int			height;
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
	t_points	start_point;
	t_points	end_point;
	int			dx;
	int			dy;
}				t_vector;

typedef struct s_zoom
{
	int			value;
	int			x;
	int			y;
}				t_zoom;

typedef struct s_map
{
	// int			param;
	int			width;
	int			height;
	int			x_nbrs;
	int			y_nbrs;
	int			tile_size;
	int			multiplier;
	char		projection;
	t_zoom		zoom;
	t_points	start_point;
	t_points	end_point;
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

#endif
