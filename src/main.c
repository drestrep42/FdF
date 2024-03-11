/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:14:01 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/11 23:20:43 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

  void	ft_leaks(void) //borrar
{
	system("leaks -q fdf");
}

void	*ms_malloc(size_t size, char *file, int line)
{
	void	*p = (malloc)(size);
	printf("%s:%d -> `%p`\n", file, line, p);
	return p;
}

int	main(int ac, char **argv)
{
	t_fdf	fdf;
	int		fd;
	
	atexit(ft_leaks);
	fd = open(argv[1], O_RDONLY);
	if (ac != 2 || ft_memcmp(argv[1], "", 1) == 0 || fd < 0)
	{
		ft_printf(ERROR_USAGE);
		exit(1);
	}
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
	{
		ft_printf(ERROR_USAGE);
		exit(1);
	}
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
