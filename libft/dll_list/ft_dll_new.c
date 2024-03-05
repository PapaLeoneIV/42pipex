/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//#include "ft_printf.h"

t_dll_list	*ft_dll_new(void *val)
{
	t_dll_list	*new;

	new = ft_calloc(1, sizeof(t_dll_list));
	if (!new)
		return (NULL);
	new->val = (int *)val;
	new->next = NULL;
	new->index = 0;
	new->prev = NULL;
	return (new);
}

/* 

int	main(void)
{
	t_dll_list *head;
	t_dll_list *first;

	head = NULL;
	first = ft_dll_new((char *)"stringa!");
	ft_printf("%s\n", first->val);

} */
