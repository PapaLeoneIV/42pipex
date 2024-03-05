/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_get_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_dll_list	*ft_dll_get_node(t_dll_list *list, int index)
{
	int			i;
	t_dll_list	*ptr;

	i = 0;
	ptr = list;
	if (!list)
		return (NULL);
	ft_dll_return_head(&ptr);
	while (ptr != NULL)
	{
		if (ptr->index == index)
			return (ptr);
		ptr = ptr->next;
		i++;
	}
	return (NULL);
}
/* 

int	main(void)
{
    int arr[] = {1, 2, 3, 4};
    int len = 4;

    t_dll_list* list = ft_dll_initi(arr, len);
    t_dll_list* res = ft_dll_get_node(list, -99);
    if(res != NULL)
        printf("res : %i\n", *(int*)res->val);
    else 
        return (0);
}  */
