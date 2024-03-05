/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_hash_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:55 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_hash_map(t_hash_map *map)
{
	int		i;
	t_item	*current;
	t_item	*temp;

	i = 0;
	while (i < map->size)
	{
		current = map->array[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp);
			temp = NULL;
		}
		i++;
	}
	free(map->array);
	free(map);
}
