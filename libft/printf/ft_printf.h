/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:37:47 by rileone           #+#    #+#             */
/*   Updated: 2023/10/26 12:37:51 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

/*funzioni principali per la logica del printf*/
int		ft_printf(char const *str, ...);
void	ft_process_variable(char c, va_list ap, int *count);
/*funzioni di supporto modificate per contare il numero di stampe*/
size_t	ft_strlen_pf(const char *s);
void	ft_putchar_pf(char c, int *count);
void	ft_putstr_pf(char *str, int *count);
void	ft_putnbr_pf(int n, int *count);
void	ft_putnbr_base_pf( int nbr, char *base, int *count);

/** @brief funzione identicata ft_putnbr_base solo per gestire i 
 * valori esadecimali (%x) / (%X)
*/
void	ft_putnbr_base_unsigned_pf(unsigned int nbr, char *base, int *count);

/**
 * @brief funzione identicata ft_putnbr_base solo per gestire i 
 * valori che sono unsigned (%u) 
*/
void	ft_putnbr_unsigned_int_pf(int n, int *count);

/**
 * @brief funzione identicata ft_putnbr_base solo per gestire i 
 * valori esadecimali del placeholder (%p) 
*/
void	ft_putnbr_base_pointers(void *nbr, char *base, int *count);

/**
 * @brief funzione di supporto per ft_putnbr_base_pointers
 * per gestire i casi in cui il valore passato sia NULL\0 
*/
void	ft_putnbr_base_pointers_help_pf(void *nbr, char *base, int *count);

#endif
