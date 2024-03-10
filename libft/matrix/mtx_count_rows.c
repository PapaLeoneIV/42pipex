/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_count_rows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:46:04 by rileone           #+#    #+#             */
/*   Updated: 2024/03/10 16:33:48 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mtx_count_rows(char **mtx)
{
	int	rows;

	rows = 0;
	while (mtx && mtx[rows] != NULL)
		rows++;
	return (rows);
}
