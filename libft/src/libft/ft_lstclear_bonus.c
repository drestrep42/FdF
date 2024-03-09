/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:41:58 by drestrep          #+#    #+#             */
/*   Updated: 2022/08/30 12:08:59 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (lst && *lst)
	{
		while (*lst)
		{
			aux = (*lst)-> next;
			del((*lst)-> content);
			free(*lst);
			*lst = aux;
		}
	}
}
