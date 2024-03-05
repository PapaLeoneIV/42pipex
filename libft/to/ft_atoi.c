/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:40 by rileone           #+#    #+#             */
/*   Updated: 2024/02/28 15:55:40 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_atoi(char *nptr, int *arr, char **mtx, int len)
{
	int		isnegative;
	long	res;

	res = 0;
	isnegative = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isnegative = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	res = res * isnegative;
	if (res > 2147483647 || res < -2147483648)
		(free(arr), ft_clear_mtx(&mtx, len), error_fn());
	return (res);
}
