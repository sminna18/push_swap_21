NAME = push_swap

SRCS =	push_swap.c sort_files.c sort_files2.c sort_files3.c\
		ft_atoi.c arg_checker.c int_changer.c sort_utils.c\
		step_work.c sort_min_nums.c ft_split_ps.c

INCLUDE = push_swap.h

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all