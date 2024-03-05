/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_find_middle_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:36:31 by rileone           #+#    #+#             */
/*   Updated: 2024/02/21 11:36:34 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_find_middle(t_dll_list *stack)
{
	int			index;
	t_dll_list	*tmp;

	tmp = stack;
	ft_dll_return_tail(&tmp);
	index = tmp->index / 2;
	return (index);
}
