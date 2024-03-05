/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:12:09 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_min(t_dll_list *a)
{
	int			min;
	int			idx;
	t_dll_list	*ptr;

	min = INT_MAX;
	ptr = a;
	while (ptr != NULL)
	{
		if (*(int *)ptr->val < min)
		{
			min = *(int *)ptr->val;
			idx = ptr->index;
		}
		ptr = ptr->next;
	}
	return (idx);
}
