/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:32:49 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/04 19:57:40 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line/get_next_line.h"

char	*ft_readed(int fd, char *readed)
{
	char	*stash;
	int		buf;

	if (!readed)
		readed = ft_calloc(sizeof(char), 1);
	stash = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buf = 1;
	while (!ft_strchr(stash, '\n') && buf != 0)
	{
		buf = read(fd, stash, BUFFER_SIZE);
		if (buf == -1)
		{
			free (readed);
			free (stash);
			return (NULL);
		}
		stash[buf] = '\0';
		readed = ft_strjoin(readed, stash);
	}
	free (stash);
	return (readed);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + definechar(stash, i)));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[10240];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash[fd] = ft_readed(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_next_line(stash[fd]);
	return (line);
}

/*
int	main(void)
{
	char	*line;
	int		fd0;
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;

	i = 1;
	fd0 = open("test00.txt", O_RDONLY);
	fd1 = open("test01.txt", O_RDONLY);
	fd2 = open("test02.txt", O_RDONLY);
	fd3 = open("test03.txt", O_RDONLY);

	while (i < 5)
	{
		line = get_next_line(fd0);
		printf("Línea %d del test 00: %s\n", i, line);
		free (line);
		line = get_next_line(fd1);
		printf("Línea %d del test 01: %s\n", i, line);
		free (line);
		line = get_next_line(fd2);
		printf("Línea %d del test 02: %s\n", i, line);
		free (line);
		line = get_next_line(fd3);
		printf("Línea %d del test 03: %s\n", i, line);
		free (line);
		i++;
	}
	close(fd0);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
