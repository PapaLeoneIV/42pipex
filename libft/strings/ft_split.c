/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:01 by rileone           #+#    #+#             */
/*   Updated: 2024/03/18 09:54:22 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int		i;
	int		res;

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
	t_split_var	var;
	char		**res;

	var = (t_split_var){0};
	var.len = count_words(s, c);
	if (!var.len)
		return (NULL);
	res = (char **)ft_calloc((var.len + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (var.j < var.len)
	{
		while (s[var.i] == c && s[var.i] != '\0')
			var.i++;
		var.length = ft_countlength(s, var.i, c);
		res[var.j] = ft_substr(s, var.i, var.length);
		if (res[var.j] == NULL)
			return (ft_clear_mtx(&res, var.len), NULL);
		var.i += var.length;
		var.j++;
	}

	return (res);
}


 /*
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
