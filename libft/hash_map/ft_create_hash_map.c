/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_hash_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:54 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_hash_map	*ft_create_hash_map(int size)
{
	t_hash_map	*map;
	int			i;

	i = 0;
	map = (t_hash_map *)malloc(sizeof(t_hash_map));
	map->size = size;
	map->n_item = 0;
	map->array = (t_item **)calloc(size, sizeof(t_item *));
	while (i < size)
	{
		map->array[i] = NULL;
		i++;
	}
	return (map);
}

/* 
int	main(void)
{
    t_hash_map * map;
    int i = 0;
    map = ft_create_t_hash_map (10);
    while(i < 10)
    {
        printf("%p\n", (void *)map->array[i]);
        i++;
    }
} */
