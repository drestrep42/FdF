/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:14:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/04/18 21:22:54 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	leaks(void)
{
	system("leaks -q fdf");
}

int	main(int ac, char **argv)
{
	t_fdf	fdf;
	int		fd;

	atexit(leaks);
	fd = open(argv[1], O_RDONLY);
	if (ac != 2 || ft_memcmp(argv[1], "", 1) == 0 || fd < 0)
		usage_error();
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		usage_error();
	fdf_init(&fdf);
	parsing(&fdf.map, fd);
	fd = open(argv[1], O_RDONLY);
	map_init(&fdf.map);
	points_init(&fdf.map, fd);
	close(fd);
	draw_map(&fdf, fdf.map);
	mlx_key_hook(fdf.win_ptr, key_hooks, &fdf);
	mlx_mouse_hook(fdf.win_ptr, mouse_hooks, &fdf);
	mlx_hook(fdf.win_ptr, CLOSE_WINDOW, 0, close_win, &fdf);
	mlx_hook(fdf.win_ptr, ON_KEYDOWN, 0, events, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
