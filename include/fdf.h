/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:06:34 by drestrep          #+#    #+#             */
/*   Updated: 2023/09/22 00:17:42 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libmlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define ERROR_USAGE "Correct use: gcc ./fdf ./maps/\"map\"\n"

#define WIDTH 1000
#define HEIGHT 1000

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		line_length;
	int		endian;
	int		bpp;
}				t_img;

typedef struct s_fdf
{
	void  *mlx_ptr;
	void  *win_ptr;
	t_img img;
	
} 		t_fdf;


// PROGRAM INITIALIZER
void	fdf_init(t_fdf *fdf);

// ERROR CONTROL
void	malloc_error(t_fdf *fdf);






#endif