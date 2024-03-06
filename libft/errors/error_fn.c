/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:50:54 by rileone           #+#    #+#             */
/*   Updated: 2024/03/06 12:28:28 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	error_fn(t_errors error_type)
{
	if(error_type == INITIALIZATION_ERROR)
		write(2, "Error in the initialization phase\n", 34);
	else if(error_type == ALLOCATION_ERROR)
		write(2, "Error in allocation!!!\n", 24);
	else if (error_type == EXEC_ERROR)
		write(2, "Error the execution of function!!\n", 35);
	else if (error_type == INVALID_INPUT)
		write(2, "Error nell input passato!!\n", 27);
	exit(1);
}
