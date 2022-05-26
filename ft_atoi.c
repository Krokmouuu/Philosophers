/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:21:59 by bleroy            #+#    #+#             */
/*   Updated: 2022/05/18 13:47:48 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long int			n;
	int					negative;
	const char			*src;
	long int			i;

	i = 0;
	src = str;
	while ((src[i] >= 9 && src[i] <= 13) || (src[i] == ' '))
		i++;
	negative = 0;
	if (src[i] == '-' || src[i] == '+')
		if (src[i++] == '-')
			negative = 1 - negative;
	n = 0;
	while (src[i] >= '0' && src[i] <= '9')
		n = src[i++] - '0' + n * 10;
	if (negative)
		n *= -1;
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (n);
}
