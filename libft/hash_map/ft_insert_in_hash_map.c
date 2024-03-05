/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_in_hash_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:55 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include "limits.h"

void	ft_insert_in_hash_map(t_hash_map *map, int key)
{
	int		riga_t_hash_map ;
	t_item	*nodo;
	t_item	*new_item;

	riga_t_hash_map = ft_hash_fn(key, map->size);
	nodo = map->array[riga_t_hash_map];
	while (nodo != NULL)
	{
		if (nodo->key == key)
		{
			nodo->value++;
			return ;
		}
		nodo = nodo->next;
	}
	new_item = (t_item *)malloc(sizeof(t_item));
	new_item->key = key;
	new_item->value = 1;
	new_item->next = NULL;
	map->array[riga_t_hash_map] = new_item;
}

/* int main() 
{
    t_hash_map * map;
    int i = 0;
    map = ft_create_t_hash_map (10);


    for (i = 0; i < 10; i++) {
        printf("Index %d: ", i);
       t_item* current = map->array[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");int main() 
{
    t_hash_map * map;
    int i = 0;
    map = ft_create_t_hash_map (10);

      ft_insert_in_t_hash_map (map, -19);
    ft_insert_in_t_hash_map (map, 2);
    ft_insert_in_t_hash_map (map, -19);
    ft_insert_in_t_hash_map (map, 1);
    ft_insert_in_t_hash_map (map, 1);
    ft_insert_in_t_hash_map (map, -99);
    ft_insert_in_t_hash_map (map, -100);
    ft_insert_in_t_hash_map (map, 4);
    ft_insert_in_t_hash_map (map, 23); 
     ft_insert_in_t_hash_map (map, INT_MAX);
    ft_insert_in_t_hash_map (map, INT_MAX);  
      ft_insert_in_t_hash_map (map, INT_MIN);
    ft_insert_in_t_hash_map (map, INT_MIN);  
  ft_insert_in_t_hash_map (map, 23242);
    ft_insert_in_t_hash_map (map, 44324); 
 ft_insert_in_t_hash_map (map, 1);
    ft_insert_in_t_hash_map (map, 2);
    ft_insert_in_t_hash_map (map, 3);
    ft_insert_in_t_hash_map (map, 4);
    ft_insert_in_t_hash_map (map, 5);
    ft_insert_in_t_hash_map (map, 6);
    ft_insert_in_t_hash_map (map, 1);  

    for (i = 0; i < 10; i++) {
        printf("Index %d: ", i);
       t_item* current = map->array[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
    int res = ft_get_frequency(map, -19);
    if(res > 1) 
    {
        printf("L'array contiene duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }
    ft_free_t_hash_map (map);

    return (0);
} duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }
    ft_free_t_hash_map (map);

    return (0);
}  */
