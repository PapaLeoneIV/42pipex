/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_int_pf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:01 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:16 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_unsigned_int_pf(int n, int *count)
{
	char			c;
	unsigned int	nl;

	nl = (unsigned int)n;
	if (nl >= 10)
	{
		ft_putnbr_pf((nl / 10), count);
	}
	c = (unsigned int)(nl % 10) + '0';
	ft_putchar_pf(c, count);
}
