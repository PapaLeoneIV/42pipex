/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rileone <rileone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:53:01 by rileone           #+#    #+#             */
/*   Updated: 2024/03/10 16:41:31 by rileone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./gnl/get_next_line_bonus.h"
# include "./printf/ft_printf.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_lis_var
{
	int					lis_lenght;
	int					arr_size;
	int					max_index;
}						t_lis_var;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_dll_list
{
	void				*val;
	int					index;
	struct s_dll_list	*prev;
	struct s_dll_list	*next;

}						t_dll_list;

typedef struct s_item
{
	int					key;
	int					value;
	struct s_item		*next;
}						t_item;

typedef struct s_hash_map
{
	int					size;
	int					n_item;
	struct s_item		**array;
}						t_hash_map;

typedef enum e_errors
{
	INITIALIZATION_ERROR,
	ALLOCATION_ERROR,
	EXEC_ERROR,
	INVALID_INPUT,
}	t_errors;

typedef enum e_state
{
	SUCCESS,
	FAILURE,
	CONTINUE,
}	t_state;

int						mtx_count_cols(char **mtx);
int						mtx_count_rows(char **mtx);

/**
 * @brief Prints an error message.
 *
 * @return void
 */
void					error_fn(t_errors error_type);

/**
 * @brief Prints an integer.
 *
 * @param n The integer to be printed.
 * @return void
 */
void					ft_putnbr(int n);

/**
 * @brief Prints a string.
 *
 * @param s The string to be printed.
 * @return void
 */
void					ft_putstr(char *s);

/**
 * @brief Prints a character.
 *
 * @param c The character to be printed.
 * @return void
 */
void					ft_putchr(char c);

/**
 * @brief Checks if a character is alphanumeric.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int						ft_isalnum(int c);

/**
 * @brief Checks if a character is alphabetic.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int						ft_isalpha(int c);

/**
 * @brief Checks if a character is ASCII.
 *
 * @param c The character to be checked.
 * @return 1 if the character is ASCII, 0 otherwise.
 */
int						ft_isascii(int c);

/**
 * @brief Checks if a character is a digit.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int						ft_isdigit(int c);

/**
 * @brief Checks if a string represents a number.
 *
 * @param str The string to be checked.
 * @return 1 if the string represents a number, 0 otherwise.
 */
int						ft_isnumber(char *str);

/**
 * @brief Checks if a character is printable.
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
 */
int						ft_isprint(int c);

/**
 * @brief Calculates the length of a string.
 *
 * @param s The string.
 * @return The length of the string.
 */
size_t					ft_strlen(const char *s);

/**
 * @brief Fills a block of memory with a specified value.
 *
 * @param s The block of memory to be filled.
 * @param c The value to be set.
 * @param n The number of bytes to be set.
 * @return A pointer to the memory block.
 */
void					*ft_memset(void *s, int c, size_t n);

/**
 * @brief Sets a block of memory to zero.
 *
 * @param s The block of memory to be set.
 * @param n The number of bytes to be set.
 * @return void
 */
void					ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of elements and initializes them to 0.
 *
 * This function allocates memory for an array of `nmemb` elements,
	each of size `size`.
 * The allocated memory is initialized to 0.
 *
 * @param nmemb The number of elements to allocate memory for.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void					*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Converts a string to an integer.
 *

	* This function parses the string pointed to by 'nptr' 
	and converts it to an integer.
 *
 * @param nptr The string to be converted.
 *
 * @return The converted integer value.
 */
int						ft_atoi(char *nptr, int *arr, char **mtx, int len);

/**
 * @brief Copies a block of memory from source to destination.
 *
 * @param dest The destination memory block.
 * @param src The source memory block.
 * @param n The number of bytes to be copied.
 * @return A pointer to the destination memory block.
 */
void					*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Clears a matrix of strings.
 *
 * @param mtx The matrix of strings.
 * @param len The length of the matrix.
 * @return void
 */
void					ft_clear_mtx(char ***mtx, int len);

/**
 * @brief Moves a block of memory from source to destination,
	handling overlapping memory blocks.
 *
 * @param dest The destination memory block.
 * @param src The source memory block.
 * @param n The number of bytes to be moved.
 * @return A pointer to the destination memory block.
 */
void					*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies a string to a destination buffer with a specified size.
 *
 * @param dest The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The length of the source string.
 */
size_t					ft_strlcpy(char *dest, char *src, size_t size);

/**
 * @brief Creates a substring of a string.
 *
 * @param s The string.
 * @param start The starting index of the substring.
 * @param len The length of the substring.
 * @return The created substring.
 */
char					*ft_substr(char const *s, unsigned int start,
							size_t len);

/**
 * @brief Concatenates two strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The concatenated string.
 */
char					*ft_strjoin(char *s1, char *s2);

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
	respectively, to be less than, to match, or be greater than s2.
 */
int						ft_strncmp(char *s1, char *s2, unsigned int n);

/**
 * @brief Searches for a character in a string.
 *
 * @param s The string.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of the character in the string,
	or NULL if the character is not found.
 */
char					*ft_strchr(const char *s, int c);

/**
 * @brief Searches for the last occurrence of a character in a string.
 *
 * @param s The string.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of the character in the string,
	or NULL if the character is not found.
 */
char					*ft_strrchr(const char *s, int c);

/**
 * @brief Copies a string to a new memory block.
 *
 * @param s The string to be copied.
 * @return The copied string.
 */
char					*ft_strdup(const char *s);

/**
 * @brief Trims leading and trailing characters from a string.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to be trimmed.
 * @return The trimmed string.
 */
char					*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Splits a string into an array of substrings.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of substrings.
 */
char					**ft_split(char const *s, char c);

/**
 * @brief Applies a function to each character of a string.
 *
 * @param s The string.
 * @param f The function to be applied.
 * @return The modified string.
 */
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));

/**
 * @brief Applies a function to each character of a string,
	passing the index as a parameter.
 *
 * @param s The string.
 * @param f The function to be applied.
 * @return void
 */
void					ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Writes a character to a file descriptor.
 *
 * @param c The character to be written.
 * @param fd The file descriptor.
 * @return void
 */
void					ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a string to a file descriptor.
 *
 * @param s The string to be written.
 * @param fd The file descriptor.
 * @return void
 */
void					ft_putstr_fd(char *s, int fd);

/**
 * @brief Writes a string followed by a newline character to a file descriptor.
 *
 * @param s The string to be written.
 * @param fd The file descriptor.
 * @return void
 */
void					ft_putendl_fd(char *s, int fd);

/**
 * @brief Writes an integer to a file descriptor.
 *
 * @param n The integer to be written.
 * @param fd The file descriptor.
 * @return void
 */
void					ft_putnbr_fd(int n, int fd);

/**
 * @brief Creates a new linked list node.
 *
 * @param content The content of the node.
 * @return The created node.
 */
t_list					*ft_lstnew(void *content);

/**
 * @brief Adds a new node at the beginning of a linked list.
 *
 * @param head The head of the linked list.
 * @param new The new node to be added.
 * @return void
 */
void					ft_lstadd_front(t_list **head, t_list *new);

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * @param lst The linked list.
 * @return The number of nodes in the linked list.
 */
int						ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of a linked list.
 *
 * @param lst The linked list.
 * @return The last node of the linked list.
 */
t_list					*ft_lstlast(t_list *lst);

/**
 * @brief Adds a new node at the end of a linked list.
 *
 * @param lst The linked list.
 * @param new The new node to be added.
 * @return void
 */
void					ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes a node from a linked list.
 *
 * @param lst The node to be deleted.
 * @param del The function used to delete the content of the node.
 * @return void
 */
void					ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes all nodes of a linked list.
 *
 * @param lst The linked list.
 * @param del The function used to delete the content of each node.
 * @return void
 */
void					ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Applies a function to each node of a linked list.
 *
 * @param lst The linked list.
 * @param f The function to be applied.
 * @return void
 */
void					ft_lstiter(t_list *lst, void (*f)(void *));

/**

	* @brief Creates a new linked list by applying a function 
	to each node of a linked list.
 *
 * @param lst The linked list.
 * @param f The function to be applied.
 * @param del The function used to delete the content of each node.
 * @return The new linked list.
 */
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

/**
 * @brief Prints an array of integers.
 *
 * @param arr The array of integers.
 * @param len The length of the array.
 * @return void
 */
void					ft_print_arri(int *arr, int len);

/**
 * @brief Checks for duplicate elements in an array.
 *
 * @param arr The array of integers.
 * @param size The size of the array.
 * @return 1 if duplicate elements are found, 0 otherwise.
 */
int						ft_check_for_dupl(int *arr, int size);

/**
 * @brief Inserts a key-value pair into a hash map.
 *
 * @param map The hash map.
 * @param key The key.
 * @return void
 */
void					ft_insert_in_hash_map(t_hash_map *map, int key);

/**
 * @brief Creates a new hash map.
 *
 * @param size The size of the hash map.
 * @return The created hash map.
 */
t_hash_map				*ft_create_hash_map(int size);

/**
 * @brief Hash function for a given key and size.
 *
 * @param key The key.
 * @param size The size of the hash map.
 * @return The hash value.
 */
int						ft_hash_fn(int key, int size);

/**
 * @brief Frees the memory allocated for a hash map.
 *
 * @param map The hash map.
 * @return void
 */
void					ft_free_hash_map(t_hash_map *map);

/**
 * @brief Gets the frequency of a key in a hash map.
 *
 * @param map The hash map.
 * @param key The key.
 * @return The frequency of the key.
 */
int						ft_get_frequency(t_hash_map *map, int key);

/**
 * @brief Checks if a doubly linked list is ordered.
 *
 * @param stack The doubly linked list to check.
 *
 * @return 1 if the list is ordered, 0 otherwise.
 */
int						ft_dll_check_if_ordered(t_dll_list *stack);

/**
 * @brief Finds the middle value in a stack.
 *
 * This function calculates and returns the middle value in a given stack.
 *
 * @param stack A pointer to the stack structure.
 * @return The middle value in the stack.
 */
int						ft_find_middle(t_dll_list *stack);

/**
 * @brief Inserts a new node at the head of a doubly linked list.
 *
 * @param head The head of the doubly linked list.
 * @param new The new node to be inserted.
 * @return void
 */
void					ft_dll_insert_head(t_dll_list **head, t_dll_list *new);

/**
 * @brief Inserts a new node at the tail of a doubly linked list.
 *
 * @param head The head of the doubly linked list.
 * @param new The new node to be inserted.
 * @return void
 */
void					ft_dll_insert_tail(t_dll_list **head, t_dll_list *new);

/**
 * @brief Creates a new doubly linked list node.
 *
 * @param val The value of the node.
 * @return The created node.
 */
t_dll_list				*ft_dll_new(void *val);

/**
 * @brief Returns the head node of a doubly linked list.
 *
 * @param lst The doubly linked list.
 * @return void
 */
void					ft_dll_return_head(t_dll_list **lst);

/**
 * @brief Returns the tail node of a doubly linked list.
 *
 * @param lst The doubly linked list.
 * @return void
 */
void					ft_dll_return_tail(t_dll_list **lst);

/**
 * @brief Calculates the size of a doubly linked list.
 *
 * @param dll The doubly linked list.
 * @return The size of the doubly linked list.
 */
int						ft_dll_size(t_dll_list *dll);

/**
 * @brief Initializes a doubly linked list with an array of integers.
 *
 * @param arr The array of integers.
 * @param len The length of the array.
 * @return The initialized doubly linked list.
 */
t_dll_list				*ft_dll_initi(int *arr, int len);

/**
 * @brief Clears a doubly linked list.
 *
 * @param lst The doubly linked list.
 * @param del The function used to delete the content of each node.
 * @return void
 */
void					ft_dll_clear(t_dll_list **lst, void (*del)(void *));

/**
 * @brief Initializes a doubly linked list with a specified length and value.
 *
 * @param len The length of the doubly linked list.
 * @param value The value to be assigned to each node.
 * @return The initialized doubly linked list.
 */
t_dll_list				*ft_dll_initi_to(int len, int value);

/**
 * @brief Updates the index of each node in a doubly linked list.
 *
 * @param head The head of the doubly linked list.
 * @return void
 */
void					ft_dll_update_index(t_dll_list **head);

/**
 * @brief Gets the node at a specified index in a doubly linked list.
 *
 * @param list The doubly linked list.
 * @param index The index of the node.
 * @return The node at the specified index.
 */
t_dll_list				*ft_dll_get_node(t_dll_list *list, int index);

/**
 * @brief Gets the value at a specified index in a doubly linked list.
 *
 * @param list The doubly linked list.
 * @param index The index of the value.
 * @return The value at the specified index.
 */
int						ft_dll_get_value(t_dll_list *list, int index);

/**
 * Finds the index of a node with the specified value in a doubly linked list.
 *
 * @param list The doubly linked list to search in.
 * @param value The value to search for.
 * @return The index of the node with the specified value, or -1 if not found.
 */
int						ft_dll_get_node_index(t_dll_list *list, int value);

/**
 * @brief Prints the values of a doubly linked list.
 *
 * @param list The doubly linked list.
 * @return void
 */
void					ft_dll_printi(t_dll_list *list);

/**
 * @brief Deletes the last node of a doubly linked list.
 *
 * @param list The doubly linked list.
 * @return void
 */
void					ft_del_lastnode(t_dll_list *list);

/**
 * @brief Gets the index of the tail node in a doubly linked list.
 *
 * @param list The doubly linked list.
 * @return The index of the tail node.
 */
int						ft_dll_get_tail_index(t_dll_list *list);

/**

	* @brief Finds the Longest Increasing Subsequence (LIS) of a 
	doubly linked list and returns it as a list.
 *
 * @param lis_len The length of the LIS.
 * @param a The doubly linked list.
 * @return The LIS as a doubly linked list.
 */
t_dll_list				*ft_lis_algo_list(int *lis_len, t_dll_list *a);

/**

	* @brief Finds the Longest Increasing Subsequence (LIS) 
	of an array and returns it as an array.
 *
 * @param arr The array.
 * @param length The length of the array.
 * @param lis_len The length of the LIS.
 * @return The LIS as an array.
 */
int						*ft_lis_algo_arr(int *arr, int length, int *lis_len);

/**
 * @brief Sorts an array using the Quick Sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param low The starting index of the array.
 * @param high The ending index of the array.
 * @return void
 */
void					ft_quick_sort(int *arr, int low, int high);

/**
 * @brief Find the minimum and maximum values in the stack.
 * @param stack_a The stack A.
 * @return int* An array containing the minimum and maximum values.
 */
int						*ft_findminmax(t_dll_list *stack_a);

/**
 * @brief Find the minimum value in the stack.
 * @param a The stack A.
 * @return int The minimum value.
 */
int						ft_find_min(t_dll_list *a);

#endif