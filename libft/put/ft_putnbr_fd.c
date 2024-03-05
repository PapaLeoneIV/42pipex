/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:01 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:16 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	nl;

	nl = (long long)n;
	if (nl < 0)
	{
		nl *= -1;
		write(fd, "-", 1);
	}
	if (nl >= 10)
	{
		ft_putnbr_fd((nl / 10), fd);
	}
	c = (unsigned int)(nl % 10) + '0';
	write(fd, &c, 1);
}
