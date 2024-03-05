/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:34:02 by rileone           #+#    #+#             */
/*   Updated: 2024/02/01 15:51:53 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strrchr(set, s1[end]))
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
/*
int	main(void)
{
	const char	s1[];
	char const	set;
	char		*result;

	s1[] = "     aaaaaaThis is stringContinue.       ";
	set = " a";
	result = ft_strtrim(s1, &set);
	printf("The result is %s\n", result);
  return (0);
}
*/
/*
 * devo scorrere la stringa s1ptr
 * se il valore di s1ptr == set[element]
 * allora devo spostare s1 fino al s1ptr
 * quando incontro il primo carattere diverso
 * devo scorrere s1ptr fino alla fine della stringa e scorrerla al contrario
 * scorrere al contrario e rifare lo stesso procedimento
*/
