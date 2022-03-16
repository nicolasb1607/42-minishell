CC= gcc
SAN= -fsanitize=address
CFLAGS= -Wall -Wextra -Werror ##$(SAN)
EXEC= minishell


LIBFT = ./libft/
RL = /usr/local/opt/readline/lib

INCLUDES = ./includes/
INCLUDESRL = /usr/local/opt/readline/include/
INCLUDESLIBFT = ./libft/

SRCS = ./main.c \
	./srcs/prompt.c \
	./srcs/builtins/pwd.c \
	./srcs/builtins/env.c \
	./srcs/builtins/cd.c \
	./srcs/builtins/unset.c \
	./srcs/builtins/export_1.c \
	./srcs/builtins/export_2.c \
	./srcs/pipe/pipex.c \
	./srcs/pipe/pipe.c \
	./srcs/pipe/run_first.c \
	./srcs/pipe/run_mid.c \
	./srcs/pipe/run_last.c \
	./srcs/pipe/utils.c \
	./srcs/pipe/more_utils.c \
	./srcs/lexer/lexer.c \
	./srcs/lexer/init_lexer.c \
	./srcs/lexer/lexer_utils.c \
	./srcs/lexer/expand_p1.c \
	./srcs/lexer/expand_p2.c \
	./srcs/utils/tab_to_list.c \
	./srcs/utils/ft_tlstnew.c \
	./srcs/utils/ft_tlstadd_back.c \
	./srcs/utils/ft_tlstlast.c \
	./srcs/utils/ft_printtoklst.c \
	./srcs/utils/ft_tlstsize.c \
	./srcs/utils/ft_tlstiter.c \
	./srcs/parser/parser.c \
	./srcs/echo.c \

OBJS = ${SRCS:.c=.o}


all : MAKELIBFT $(EXEC)


$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS)  -L $(LIBFT) -L $(RL) $^ -o $(EXEC) -I $(INCLUDES) -I $(INCLUDESRL) -I $(INCLUDESLIBFT) -lft -lreadline -g

.c.o:
	$(CC) $(CFLAGS)  -L $(LIBFT) -L $(RL) -c $^ -o $@ -I $(INCLUDES) -I $(INCLUDESRL) -I $(INCLUDESLIBFT) -lft -lreadline -g

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
	
