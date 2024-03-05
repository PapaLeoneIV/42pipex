/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_frequency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:55 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_get_frequency(t_hash_map *map, int key)
{
	int		index;
	t_item	*current;

	index = ft_hash_fn(key, map->size);
	current = map->array[index];
	while (current != NULL)
	{
		if (current->key == key)
			return (current->value);
		current = current->next;
	}
	return (0);
}
