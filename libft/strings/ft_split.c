/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:01 by rileone           #+#    #+#             */
/*   Updated: 2024/03/06 15:07:40 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	*ft_strdup2(const char *s, int i, int length)
{
	char	*arr;
	int		j;

	j = 0;
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (!arr)
		return (NULL);
	while (j < length)
	{
		arr[j] = s[i + j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
} */

static int	count_words(const char *str, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			res += 1;
		i++;
	}
	return (res);
}

static int	ft_countlength(const char *str, int i, char c)
{
	int	length;

	length = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		length++;
	}
	return (length);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;
	int		length;
	int		j;

	j = 0;
	length = 0;
	i = 0;
	len = count_words(s, c);
	if (!len)
		return (NULL);
	res = (char **)ft_calloc((len + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (j < len)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		length = ft_countlength(s, i, c);
		res[j] = ft_substr(s, i, length);
		if (res[j] == NULL)
			return (ft_clear_mtx(&res, len), NULL);
		j++;
		i += length;
	}
	return (res);
}
/* 
 static void	ft_print_res(char const *s)
 {
 	int		len;

 	len = 0;
 	while (s[len])
 		len++;
 	write(1, s, len);
 	write(1, "\n", 1);
 }
 int main()
 { 
	char *str = "    abcde fghil    ";
	char c = ' ';
	char **res;
	res = ft_split(str, c);
	int i = 0;

		while (res[i] != NULL)
		{
			ft_print_res(res[i]);
			free(res[i]);
			i++;
		}
			free(res);

	return (0);
 }
 */
