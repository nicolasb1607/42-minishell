CC= gcc
CFLAGS= -Wall -Wextra -Werror
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
	./srcs/builtins/export.c \
	./srcs/pipe/pipex.c \
	./srcs/pipe/pipe.c \
	./srcs/lexer.c \
	./srcs/pipe/run_first.c \
	./srcs/pipe/run_mid.c \
	./srcs/pipe/run_last.c \
	./srcs/pipe/utils.c \
	./srcs/pipe/more_utils.c \

OBJS = ${SRCS:.c=.o}


all : MAKELIBFT $(EXEC)


$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) -L $(RL) $^ -o $(EXEC) -I $(INCLUDES) -I $(INCLUDESRL) -I $(INCLUDESLIBFT) -lft -lreadline -g

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
	
