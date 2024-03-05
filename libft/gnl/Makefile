NAME = libgnl.a
CC = cc 
CFLAGS = -Wall -Werror -Wextra
COMPILE = $(CC) $(CFLAGS) 

AR = ar rc $(NAME)

REM = rm -f

SRC =	./get_next_line_bonus.c \
		./get_next_line_utils_bonus.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@$(COMPILE) -c $<  -o $@ 

clean:
	@$(REM) $(OBJ)


fclean: clean
	@$(REM) $(NAME)

re: fclean all

main: re
	@$(COMPILE) main.c -L. -lftprintf

.PHONY: all clean fclean re 


