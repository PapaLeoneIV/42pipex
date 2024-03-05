/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:46:10 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;
	char	c1;

	a = (char *)s;
	c1 = (char)c;
	while (n > 0)
	{
		if (*a == c1)
			return (a);
		a++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	int	tab[];

    tab[] = {0, 1, 2 ,3 ,4 ,5};
	printf("%ls",tab + 2);
	if(ft_memchr(tab, 2 + 256, 3) == tab + 2)
		printf("nicenicenicenice");
	else 
		printf("non nice dude");
}

*/
