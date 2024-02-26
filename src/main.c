/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:14:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/25 20:24:49 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int ac, char **argv)
{
	t_fdf	fdf;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (ac != 2 || ft_memcmp(argv[1], "", 1) == 0 || !((fd) >= 0))
	{
		printf(ERROR_USAGE);
		exit(1);
	}
	/* ft_printf("%d\n", fdf.map.points.color);
	exit(0); */
	fdf = fdf_init();
	fdf.map = parsing(fdf.map, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	fdf.map.coord = points_init(fdf.map, fd);
	close(fd);
	fdf.map = map_init(fdf.map);
	mlx_key_hook(fdf.win_ptr, handle_input, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, close_win, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}


// MODIFY VALUES FUNCTION IN DRAW_LINE.C FILE
