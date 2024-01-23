/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:35:33 by drestrep          #+#    #+#             */
/*   Updated: 2024/01/04 19:58:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:26:28 by drestrep          #+#    #+#             */
/*   Updated: 2023/06/15 11:11:07 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line/get_next_line.h"

int definechar(char *stash, int i)
{
    if (stash[i] == '\n')
        return (2);
    else
        return (1);
}

char	*ft_next_line(char *readed)
{
	char	*nl;
	int		i;
	int		j;

	i = 0;
	while (readed[i] != '\n' && readed[i])
		i++;
	if (!readed[i])
	{
		free(readed);
		return (NULL);
	}
	nl = malloc(sizeof(char) * (ft_strlen(readed) - i + 1));
	if (!nl)
		return (NULL);
	i++;
	j = 0;
	while (readed[i])
		nl[j++] = readed[i++];
	nl [j] = '\0';
	free(readed);
	return (nl);
}
