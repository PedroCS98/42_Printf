NAME = libftprintf.a
SRCS = 
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	@ar rsc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(BONUS_SRCS:.c=.o)

fclean: clean
	@rm -f $(NAME)
 
re: fclean all
