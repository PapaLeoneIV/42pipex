/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:12 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_variable(char c, va_list ap, int *count)
{
	if (c == 'c')
		ft_putchar_pf(va_arg(ap, int), count);
	else if (c == 's')
		ft_putstr_pf(va_arg(ap, char *), count);
	else if (c == 'i')
		ft_putnbr_pf(va_arg(ap, int), count);
	else if (c == 'p')
		ft_putnbr_base_pointers(va_arg(ap, void *), HEX_LOWER, count);
	else if (c == 'd')
		ft_putnbr_base_pf(va_arg(ap, uintptr_t), DECIMAL, count);
	else if (c == 'u')
		ft_putnbr_unsigned_int_pf(va_arg(ap, int), count);
	else if (c == 'x')
		ft_putnbr_base_unsigned_pf(va_arg(ap, uintptr_t), HEX_LOWER, count);
	else if (c == 'X')
		ft_putnbr_base_unsigned_pf(va_arg(ap, uintptr_t), HEX_UPPER, count);
	else if (c == '%')
		ft_putchar_pf('%', count);
}
