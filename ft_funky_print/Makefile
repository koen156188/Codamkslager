
NAME := libftprintf.a
HEADER = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCFILES = ft_printf.c \
		

OBJFILES = $(SRCFILES:%.c=%.o)

$(NAME): $(OBJFILES)
	$(AR) $(NAME) $(OBJFILES) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)


clean:
	@$(RM) $(OBJFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re