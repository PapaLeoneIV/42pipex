/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_minmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_findminmax(t_dll_list *stack_a)
{
	t_dll_list	*ptr;
	int			*minmax;
	int			min;
	int			max;

	ptr = stack_a;
	min = INT_MAX;
	max = INT_MIN;
	while (ptr != NULL)
	{
		if (*(int *)ptr->val < min)
			min = *(int *)ptr->val;
		if (*(int *)ptr->val > max)
			max = *(int *)ptr->val;
		ptr = ptr->next;
	}
	minmax = ft_calloc(2, sizeof(int));
	if (minmax == NULL)
		return (NULL);
	minmax[0] = min;
	minmax[1] = max;
	return (minmax);
}
