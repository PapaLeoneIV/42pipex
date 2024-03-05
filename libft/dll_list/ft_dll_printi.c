/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_printi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void	ft_dll_printi(t_dll_list *list)
{
	t_dll_list	*ptr;

	ptr = list;
	ft_printf("\n[Lista] : ");
	while (ptr != NULL)
	{
		ft_printf("\n\tidx->[%i]  :  [%i]", ptr->index, *(int *)(ptr->val));
		ptr = ptr->next;
	}
	ft_printf("\n");
}
