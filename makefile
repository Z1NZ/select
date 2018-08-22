CC    = gcc  -Wall -Wextra -Werror

RM    = rm -f

NAME    = ft_select

SRC    = ft_select.c\
		display_init.c \
		ft_move.c \
		ft_pre_select.c \
		ft_putscreen.c \
		ft_putspace.c \
		ft_return.c \
		ft_unselect.c \
		ft_unselect_form_tab.c \
		my_outc.c \
		ft_signal.c \
		ft_remove.c \

OBJS    = $(SRC:.c=.o)
SRCDIR 	= ./srcs/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
all : $(NAME)

$(NAME):
	@make -C libftprintf
	@$(CC) -I libftprintf/includes/ -c $(SRCS)
	@$(CC) $(SRCS) -lncurses -o $(NAME) libftprintf/libftprintf.a -L libftprintf/libft -lft

clean:
	@$(RM) $(OBJS) 
	@make clean -C libftprintf

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libftprintf

re: fclean all

.PHONY: all clean fclean re
