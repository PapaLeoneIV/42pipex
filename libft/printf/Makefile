NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Werror -Wextra
COMPILE = $(CC) $(CFLAGS) 

AR = ar rc $(NAME)

REM = rm -f

SRC =	./ft_printf.c \
		./ft_process_variable.c \
		./ft_putchar_pf.c \
		./ft_putstr_pf.c \
		./ft_putnbr_pf.c \
		./ft_putnbr_base_unsigned_pf.c \
		./ft_putnbr_unsigned_int_pf.c \
		./ft_putnbr_base_pf.c \
		./ft_strlen_pf.c \
		./ft_putnbr_base_pointers.c \
		./ft_putnbr_base_pointers_help_pf.c \
		
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


