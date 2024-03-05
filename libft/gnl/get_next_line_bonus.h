/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <riccardo.leone@student.42fir      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:04:20 by rileone           #+#    #+#             */
/*   Updated: 2023/11/17 19:04:25 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/**
 * @brief Funzione che attraverso la libreria fcntl legge BUFFER_SIZE
 *  caratteri da un file e ritorna ad ogni chiamata una nuova riga di
 *  testo di questo file.
 * 
 * Return Values :  - Una nuova riga di testo seguita da "\n"
 *                  - NULL se non ci sono piu righe da leggere
 * 
 * Parametri necessari :(fd) File Descriptor di un file
 * 
*/
char	*get_next_line(int fd);

/**
 * @brief tipica funzione per calcolare la lunghezza di una stringa,
 *  leggermente piu sicura perche protegge da eventuali parametri NULL
 *  mica come quel bruciato di chsassi <3
*/
int		ft_strlen_gnl(char *str);

/**
 * @brief Funzione utilizzata per allocare memoria e riempirla di 0
*/
void	*ft_calloc_gnl(size_t nmemb, size_t size);

/** Funzione StrJoin ma in grado di joinare anche una striga vuota
 * leggermente meno sicura ma utile per lo svolgimento di questo progetto
 * 
*/
char	*ft_strjoin_gnl(char *s1, char *s2, int bytes);

/**
 * @brief Funzione Substr che ritorna la sottostringa desiderata, 
 * una volta forniti un indice di partenza e un indice che
 * rappresenti la lunghezza dei caratteri da tagliare
*/
char	*ft_substr_gnl(char *s, unsigned int start, int len);

/**
 * @brief Funzione simile a strchr ma questa ritorna :
 *  - (-1) quando il carattere passato come argomento non e' 
 *          presente all interno della riga
 *  - return >= 0 quando invece il char da cercare e' presente
*/
int		ft_strchri_gnl(char *s, int c);

#endif
