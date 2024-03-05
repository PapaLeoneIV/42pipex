/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_lastnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_del_lastnode(t_dll_list *list)
{
	t_dll_list	*tmp;

	tmp = list;
	if (!list)
		return ;
	while (tmp != NULL)
	{
		if (tmp->next->next == NULL)
		{
			free(tmp->next);
			tmp->next = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}
