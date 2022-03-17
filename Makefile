SRCS = src/get_map_and_check.c src/take_image.c src/main.c src/game_finish.c\
	   src/msg_error.c src/key_events.c src/put_image_to_window.c

SRCS_BONUS = bonus/write_screen.c

SRCS_MAND  = src/write_screen.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

CC = @gcc

MFLAGS =  ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

CFLAGS = -Wall -Wextra -Werror -I./mlx -I./libft -I./ft_printf

RM = @rm -rf

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS) $(SRCS_MAND:.c=.o)
	make -C ./libft
	make -C ./ft_printf
	make -C ./get_next_line
	$(CC) $(OBJS) $(SRCS_MAND:.c=.o) $(MFLAGS) $(CFLAGS) $(NAME)

fclean : clean
	$(RM) ./libft/*.a
	$(RM) ./src/*.a
	$(RM) ./ft_printf/*.a
	$(RM) $(NAME)

clean :
	$(RM) ./libft/*.o
	$(RM) ./src/*.o
	$(RM) ./ft_printf/*.o

re : fclean all

.PHONY : all fclean clean re
