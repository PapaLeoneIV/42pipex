/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_mtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:55 by rileone           #+#    #+#             */
/*   Updated: 2024/02/28 19:20:09 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_mtx(char ***mtx, int len)
{
	int	i;

	i = 0;
	if (!mtx || !(*mtx) || !(**mtx))
		return ;
	while (i < len)
	{
		free(*(*mtx + i));
		*(*mtx + i) = NULL;
		i++;
	}
	free(*(mtx));
	*(mtx) = NULL;
}
