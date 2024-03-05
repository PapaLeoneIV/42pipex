/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned_pf.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:12 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:16 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkerror(char *str)
{
	int		i;
	size_t	j;
	size_t	x;

	x = ft_strlen_pf((const char *)str);
	i = 0;
	if (str[0] == '\0' || x == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (j < ft_strlen_pf((const char *)str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_unsigned_pf(unsigned int nbr, char *base, int *count)
{
	int		len;
	int		error;
	long	nb;

	error = checkerror(base);
	len = ft_strlen_pf(base);
	nb = nbr;
	if (error == 1)
	{
		if (nb < 0)
		{
			ft_putchar_pf('-', count);
			nb *= -1;
		}
		if (nb < len)
			ft_putchar_pf(base[nb], count);
		if (nb >= len)
		{
			ft_putnbr_base_unsigned_pf(nb / len, base, count);
			ft_putnbr_base_unsigned_pf(nb % len, base, count);
		}
	}
}
