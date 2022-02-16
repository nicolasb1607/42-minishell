CC= gcc
CFLAGS= -Wall -Wextra -Werror
EXEC= minishell

LIBFT = ./libft/
RL = /usr/local/opt/readline/lib

INCLUDES = ./includes/
INCLUDESRL = /usr/local/opt/readline/include/

SRCS = ./main.c \
	./srcs/prompt.c \

OBJS = ${SRCS:.c=.o}

all : MAKELIBFT $(EXEC)

.o : .c
	$(CC) $(CFLAGS) -c -L $(LIBFT) -L $(RL) $^ -I $(INCLUDES) -I $(INCLUDESRL) -lft -lreadline

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) -L $(RL) $^ -o $(EXEC) -I $(INCLUDES) -I $(INCLUDESRL) -lft -lreadline 

MAKELIBFT : 
	make -C $(LIBFT)

clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -rf $(EXEC)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re 
	
