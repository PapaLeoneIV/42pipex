/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pointers.c                          :+:      :+:    :+:   */
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

void	ft_putnbr_base_pointers(void *nbr, char *base, int *count)
{
	size_t	len;
	int		error;
	size_t	nb;

	if (!(uintptr_t)nbr)
	{
		ft_putstr_pf("(nil)", count);
		return ;
	}
	error = checkerror(base);
	len = ft_strlen_pf(base);
	nb = (size_t)nbr;
	if (error == 1)
	{
		ft_putstr_pf("0x", count);
		if (nb < len)
			ft_putchar_pf(base[nb], count);
		if (nb >= len)
		{
			ft_putnbr_base_pointers_help_pf((void *)(nb / len), base, count);
			ft_putnbr_base_pointers_help_pf((void *)(nb % len), base, count);
		}
	}
}
