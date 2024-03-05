/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:31:04 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:51:53 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			result = (char *)&s[i];
			return (result);
		}
		i--;
	}
	return (0);
}

/*
int	main(void)
{
	char	*str1;
	char	chare;

	
	str1 = "caSsa";
	chare = 'A';
	printf("risultato : %s \n", ft_strrchr(str1, chare));
	printf("risultato : %s", strrchr(str1, chare));
	return (0);
	
	
}

{
	char *ptr;
	unsigned int len;
	unsigned int counter;

	len = (strlen(s) - 1);
	ptr = (char *)s;
	counter = 0;
	while (counter++ < len)
		ptr++;
	while (*ptr != '\0' && *ptr != (char)c) 
		ptr--;
	return (ptr);
}*/
