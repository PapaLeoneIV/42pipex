/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dll_clear(t_dll_list **lst, void (*del)(void *))
{
	t_dll_list	*ptr;
	t_dll_list	*temp;

	if (!*lst || !lst || !del)
		return ;
	ptr = (*lst);
	ft_dll_return_head(&ptr);
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = temp->next;
		free(temp->val);
		free(temp);
	}
	*lst = NULL;
}
