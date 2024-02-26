/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:56:07 by drestrep          #+#    #+#             */
/*   Updated: 2024/02/22 16:14:23 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft/libft.h"

char	*ft_revstrchr(const char *s, int c)
{
	char	*substr;
	int		counter;

	counter = 0;
	while (s[counter] != '\n' && s[counter] != '\0' && s[counter] != (char)c)
		counter++;
	substr = malloc(counter + 1);
	if (!substr)
		return (NULL);
	substr = ft_substr(s, 0, counter);
	substr[counter] = '\0';
	return (substr);
}

/* int main(void)
{
	printf("%s\n", ft_revstrchr("Hello there", ' '));
} */
