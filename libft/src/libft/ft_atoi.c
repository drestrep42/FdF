/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:14:56 by drestrep          #+#    #+#             */
/*   Updated: 2024/04/18 17:35:00 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft/libft.h"

void	check_size(double res)
{
	if (res > INT32_MAX || res < INT32_MIN)
	{
		ft_printf("All numbers must be within INT max and min\n", res);
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	double	res;
	int		sgn;
	int		i;

	res = 0;
	sgn = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	check_size(sgn * res);
	return (sgn * (int)res);
}
