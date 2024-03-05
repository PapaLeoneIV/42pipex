NAME = libft.a
HNAME = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c -g
ARCHIVE = ar rc
DLL_DIR = dll_list
ERROR_DIR = errors
HASH_DIR = hash_map
IS_DIR = is
MEM_DIR = mem
PRINTF_DIR = printf
PUT_DIR = put
SLL_DIR = sll_list
STRING_DIR = strings
TO_DIR = to
ALGO_DIR = algorithms
MATH = math
GNL_DIR = gnl
MATRIX_DIR	= matrix

SRC =		$(addprefix ${ERROR_DIR}/, error_fn.c) \
			$(addprefix ${MATRIX_DIR}/, mtx_count_cols.c mtx_count_rows.c ) \
			$(addprefix ${MATH}/, check_if_ordered.c ft_find_min.c ft_find_minmax.c )  \
			$(addprefix ${TO_DIR}/, ft_atoi.c ft_itoa.c)  \
			$(addprefix ${IS_DIR}/, ft_isnumber.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c)  \
			$(addprefix ${STRING_DIR}/, ft_toupper.c ft_split.c /ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c) \
			$(addprefix ${PUT_DIR}/, ft_putchar_fd.c ft_putchr.c ft_putstr.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr_fd.c ft_print_arri.c) \
			$(addprefix ${MEM_DIR}/, ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c ft_clear_mtx.c) \
			$(addprefix ${HASH_DIR}/, ft_create_hash_map.c ft_free_hash_map.c ft_get_frequency.c ft_hash_fn.c ft_insert_in_hash_map.c ft_check_for_dupl.c) \
			$(addprefix ${DLL_DIR}/, ft_dll_find_middle_index.c ft_dll_check_if_ordered.c ft_dll_get_node_index.c ft_dll_insert_head.c ft_dll_insert_tail.c ft_dll_new.c ft_dll_return_head.c ft_dll_return_tail.c ft_dll_size.c ft_dll_clear.c ft_dll_initi.c ft_dll_initi_to.c ft_dll_update_index.c ft_dll_get_node.c ft_dll_get_value.c ft_dll_printi.c ft_del_lastnode.c ft_dll_get_tail_index.c) \
			$(addprefix ${SLL_DIR}/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c) \
			$(addprefix ${ALGO_DIR}/, ft_lis_algo_list.c ft_quick_sort.c ft_lis_algo_arr.c) \

OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@ -I. -Iprintf -Ignl

$(NAME): $(OBJ) 
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(ARCHIVE) $(NAME) $(OBJ)
	
clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re printf gnl