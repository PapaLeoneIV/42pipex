/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_count_cols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:44:53 by rileone           #+#    #+#             */
/*   Updated: 2024/02/28 17:34:56 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mtx_count_cols(char **mtx)
{
	int	cols;

	cols = 0;
	if (!mtx || !mtx[0])
		return (0);
	while (mtx && mtx[0][cols])
		cols++;
	return (cols);
}
