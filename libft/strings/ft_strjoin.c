/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:01 by rileone           #+#    #+#             */
/*   Updated: 2024/03/03 12:18:39 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)ft_calloc((len + 1), sizeof(char));
	if (!(out))
		return (0);
	len = 0;
	while (s1 && s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2 && s2[i])
	{
		out[len++] = s2[i];
		i++;
	}
	return (out);
}

/*
int	main(void)
{
	const char	*str;
	const char	*str1;
    char *str2;

	str = "lorem ipsum";
    str1 = "dolor sit amet";
    str2 = ft_strjoin(str, str1);
    printf("questa e' la sottostringa : %s\n", str2);
}
*/
