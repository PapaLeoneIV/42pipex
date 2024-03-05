/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_return_head.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:50 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dll_return_head(t_dll_list **lst)
{
	if (!(*lst) || !lst)
		return ;
	while ((*lst)->prev)
	{
		*lst = (*lst)->prev;
	}
}

/*  int main()
{
	int b[4] = {1, 2, 3, 4};
	t_dll_list *a = ft_dll_initi(b, 4);

	while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		if(a->next == NULL)
			break ;
		a = a->next;
	}
	ft_dll_return_head(&a);
	while(a != NULL)
	{
		printf("%i\n", *(int *)a->val);
		a = a->next;
	}
} */
