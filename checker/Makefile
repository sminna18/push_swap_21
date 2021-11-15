NAME = checker

SRCS =	checker.c ../sort_files.c ../sort_files2.c ../sort_files3.c\
		ft_strncmp.c c_arg_checker.c c_int_changer.c ../ft_split_ps.c\
		get_next_line.c get_next_line_utils.c ../ft_atoi.c ../sort_utils.c

INCLUDE = checker.h

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