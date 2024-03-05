/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:12 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_pf(*str, &count);
			str++;
		}
		else if (*str++ == '%')
		{
			ft_process_variable(*str, ap, &count);
			str++;
		}
	}
	va_end(ap);
	return (count);
}
