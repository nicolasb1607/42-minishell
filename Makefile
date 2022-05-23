CC		= gcc
SAN		= -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -g3 #$(SAN)
EXEC	= minishell


LIBFT 	= ./libft/
PRINTF	= ./printf/
RL 		= /usr/local/opt/readline/lib

INCLUDES		= ./includes/
INCLUDESRL		= /usr/local/opt/readline/include/
INCLUDESLIBFT	= ./libft/
INCLUDESPRINTF	= ./printf/

SRCS = ./main.c \
	./srcs/prompt.c \
	./srcs/builtins/pwd.c \
	./srcs/builtins/env.c \
	./srcs/builtins/cd.c \
	./srcs/builtins/unset.c \
	./srcs/builtins/export_1.c \
	./srcs/builtins/export_2.c \
	./srcs/builtins/export_3.c \
	./srcs/pipe/pipe.c \
	./srcs/pipe/utils.c \
	./srcs/pipe/more_utils.c \
	./srcs/pipe/piping.c \
	./srcs/pipe/open_io.c \
	./srcs/pipe/open_io_2.c \
	./srcs/pipe/multipipe.c \
	./srcs/pipe/multipipe_2.c \
	./srcs/pipe/mpipe_utils.c \
	./srcs/lexer/lexer.c \
	./srcs/lexer/init_lexer.c \
	./srcs/lexer/lexer_utils.c \
	./srcs/lexer/lexer_utils2.c \
	./srcs/lexer/expand_p1.c \
	./srcs/lexer/expand_p2.c \
	./srcs/lexer/expand_p3.c \
	./srcs/lexer/position.c \
	./srcs/lexer/make_token.c \
	./srcs/utils/tab_to_list.c \
	./srcs/utils/ft_tlstnew.c \
	./srcs/utils/ft_tlstadd_back.c \
	./srcs/utils/ft_tlstlast.c \
	./srcs/utils/ft_tlstsize.c \
	./srcs/utils/ft_tlstiter.c \
	./srcs/utils/ft_tlstdelone.c \
	./srcs/utils/print_tab.c \
	./srcs/utils/ft_split_custom.c \
	./srcs/utils/ft_split_cust_2.c \
	./srcs/parser/parser.c \
	./srcs/echo.c \
	./srcs/init_ft.c \
	./srcs/free.c \
	./srcs/exec/tlst_to_cmd1.c \
	./srcs/exec/tlst_to_cmd2.c \
	./srcs/exec/tlst_to_cmd_utils.c \
	./srcs/exec/heredocs.c \
	./srcs/exec/exec_utils.c \
	./srcs/exec/count_command.c \
	./srcs/handle_sig.c \
	./srcs/builtins/exit.c \
	./srcs/utils/init_ft_utils.c \
	./srcs/utils/init_ft_free.c \
	./srcs/utils/init_ft_mkcmd.c \

OBJS = ${SRCS:.c=.o}


all : MAKEPRINTF MAKELIBFT $(EXEC)

MAKEPRINTF : 
	make -C $(PRINTF)

MAKELIBFT : 
	make -C $(LIBFT)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS)  -L $(LIBFT) -L $(RL) -L $(PRINTF) $^ -o $(EXEC) -I $(INCLUDES) -I $(INCLUDESRL) -I $(INCLUDESLIBFT) -I $(INCLUDESPRINTF) -lftprintf -lft -lreadline -g

.c.o:
	$(CC) $(CFLAGS)  -L $(LIBFT) -L $(RL) -L $(PRINTF) -c $^ -o $@ -I $(INCLUDES) -I $(INCLUDESRL) -I $(INCLUDESLIBFT)  -I $(INCLUDESPRINTF) -lftprintf -lft -lreadline -g



clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)

fclean : clean
	rm -rf $(EXEC)
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)

re : fclean all

.PHONY : all clean fclean re 
