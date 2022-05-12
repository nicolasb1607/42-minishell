CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBNAME = libftprintf.a

SRCS = ./ft_printf.c \
	./ft_char_str.c \
	./ft_strchr.c \
	./ft_number.c

OBJS = ${SRCS:.c=.o}


all : EXEC

EXEC : $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(LIBNAME) 

re : fclean all 

.PHONY : all clean fclean re
