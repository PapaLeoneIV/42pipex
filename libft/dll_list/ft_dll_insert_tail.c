/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_insert_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dll_insert_tail(t_dll_list **head, t_dll_list *new)
{
	t_dll_list	*temp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	ft_dll_return_tail(head);
	temp = *head;
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
	new->index = (temp->index) + 1;
	ft_dll_return_head(head);
}
