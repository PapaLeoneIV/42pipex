/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_dupl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:54 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "limits.h"

int	ft_check_for_dupl(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* int ft_check_for_dupl(int *arr, int size)
{
    t_hash_map  *map;
    int i;
    int res;

    i = -1;
    res = 0;
    map = ft_create_t_hash_map (size);
    while(++i < size)
        ft_insert_in_t_hash_map (map, arr[i]);
    i = -1;
    while(++i < size)
    {
        res = ft_get_frequency(map, arr[i]);
        if(res > 1)
        {
            ft_free_t_hash_map (map);
            return (1);
        }  
    }
    ft_free_t_hash_map (map);
    return (0);
} */

/* int main() 
{
    int array[] = {INT_MIN, 7, 1, 3, 2, 0, INT_MAX};
    int size = sizeof(array) / sizeof(array[0]);

    if (ft_check_for_dupl(array, 10)) 
    {
        printf("L'array contiene duplicati.\n");
    } 
    else 
    {
        printf("L'array non contiene duplicati.\n");
    }

    return (0);
}  */
