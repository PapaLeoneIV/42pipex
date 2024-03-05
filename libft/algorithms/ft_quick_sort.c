/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:47:49 by rileone           #+#    #+#             */
/*   Updated: 2024/02/18 17:12:15 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	quick_sort_partition(int *arr, int low, int high)
{
	int	j;
	int	i;

	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= arr[high])
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	ft_quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = quick_sort_partition(arr, low, high);
		ft_quick_sort(arr, low, pivot - 1);
		ft_quick_sort(arr, pivot + 1, high);
	}
}

/* int main() {
    int data[] = {4,3,2,1};
    int n = sizeof(data) / sizeof(data[0]);
    printf("Unsorted Array\n");
    printArray(data, n);

    ft_quick_sort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);



    return (0);
}
 */
