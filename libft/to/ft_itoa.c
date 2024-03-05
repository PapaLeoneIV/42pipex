/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:53:28 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:51:53 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	numlen(long number)
{
	int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number *= -1;
		length++;
	}
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static void	ft_finalchar(int neg, char *array, int length, long number)
{
	if (neg == 1)
		array[length] = '-';
	else
		array[0] = (number % 10) + 48;
}

static char	*ft_itoa_helper(char *array, int neg, int length, long number)
{
	if (number == 0)
	{
		array[0] = '0';
		array[length] = '\0';
		return (array);
	}
	array[length] = '\0';
	if (number < 0)
	{
		neg = 1;
		number *= -1;
	}
	while (--length)
	{
		array[length] = (number % 10) + 48;
		number /= 10;
	}
	ft_finalchar(neg, array, length, number);
	return (array);
}

char	*ft_itoa(int n)
{
	char	*array;
	char	*result;
	int		length;
	int		neg;
	long	number;

	number = n;
	neg = 0;
	length = numlen(number);
	array = (char *)malloc(sizeof(char) * (length + 1));
	if (!array)
		return (NULL);
	result = ft_itoa_helper(array, neg, length, number);
	if (!(result))
		return (NULL);
	return (result);
}

/*
int	main(void) {
  int i = 0;
  int tab[5] = {-2147483648, -2147483647, -42, 0, 2147483647};

  while (i < 5)
    printf("%s\n", ft_itoa(tab[i++]));

  return (0);
}
*/
