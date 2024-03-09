/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:51:41 by drestrep          #+#    #+#             */
/*   Updated: 2024/03/09 20:00:52 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MALLOC
#define MS_MALLOC

#include <stdlib.h>

#if 0
	#define malloc(size) ms_malloc(size, __FILE__, __LINE__)
#endif

void	*ms_malloc(size_t size, char *file, int line);

#endif //MS_MALLOC