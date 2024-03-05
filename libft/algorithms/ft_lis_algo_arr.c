/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_algo_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "limits.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_initialize_arrays(int **len_arr, int **index_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*len_arr)[i] = 1;
		(*index_arr)[i] = -1;
		i++;
	}
}

static void	ft_find_biggest_index(t_lis_var *var, int *len_arr)
{
	int	i;

	i = 1;
	while (i < var->arr_size)
	{
		if (len_arr[i] > len_arr[var->max_index])
			var->max_index = i;
		i++;
	}
}

static void	ft_get_indexs_lis(int *arr, int **len_arr, int **index_arr, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && (*len_arr)[i] < (*len_arr)[j] + 1)
			{
				(*len_arr)[i] = (*len_arr)[j] + 1;
				(*index_arr)[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*ft_build_lis_arr(int *arr, int *len_arr, t_lis_var *var, int *index_arr)
{
	int	*res;
	int	index_counter;
	int	len_counter;

	res = ft_calloc(len_arr[var->max_index], sizeof(int));
	var->lis_lenght = len_arr[var->max_index];
	index_counter = var->max_index;
	len_counter = var->lis_lenght - 1;
	while (index_counter >= 0 && len_counter >= 0)
	{
		res[len_counter] = arr[index_counter];
		index_counter = index_arr[index_counter];
		len_counter--;
	}
	return (res);
}

int	*ft_lis_algo_arr(int *arr, int length, int *lis_len)
{
	int			*len_arr;
	int			*index_arr;
	int			*result;
	t_lis_var	var;

	var = (t_lis_var){0};
	var.arr_size = length;
	var.lis_lenght = *lis_len;
	len_arr = ft_calloc(var.arr_size, sizeof(int));
	index_arr = ft_calloc(var.arr_size, sizeof(int));
	ft_initialize_arrays(&len_arr, &index_arr, var.arr_size);
	ft_get_indexs_lis(arr, &len_arr, &index_arr, var.arr_size);
	ft_find_biggest_index(&var, len_arr);
	result = ft_build_lis_arr(arr, len_arr, &var, index_arr);
	*lis_len = var.lis_lenght;
	free(len_arr);
	free(index_arr);
	return (result);
}

/* 
 
int	main(void) {
    int arr[] = {0, 2, 34, 23, 1, 43, 53352,25324, 523, 53,532,5123 ,2};
    
    
    int lenght = sizeof(arr) / sizeof(arr[0]);
    int lis_length;
    lis_length = 1;
    int* lis_sequence = ft_lis_algo(arr, lenght, &lis_length);

    printf("LIS: ");
    for (int i = 0; i < lis_length; i++) {
        printf("%d ", lis_sequence[i]);
    }
    printf("\n");

    free(lis_sequence);

  return (0);
}   */
