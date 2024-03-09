NAME = pipex
LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/printf
GNL_DIR = ./libft/gnl
EVERY_INCLUDES=-I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
COMPILE = $(CC) $(CFLAGS)
ARCHIVE = ar rcs

SRC = pipex.c \
		pipex_utils.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(COMPILE) $(CFLAGS) -I. -I$(EVERY_INCLUDES) $(OBJ) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(PRINTF_DIR) -lftprintf -o $(NAME) 

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
