NAME=ft_ls
CC=cc

CFLAGS = -I libft -Wall -Wextra -Werror -g3

FILES=main \
	parsing/parsing \
	errors/errors

SOURCES= $(foreach f, $(FILES), srcs/$(f).c)
OBJECTS= $(foreach f, $(FILES), objects/$(f).o)

LIBFT=libft/libft.a


$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

objects/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C libft clean

fclean:
	rm -rf $(NAME) $(LIBFT) objects
	$(MAKE) -C libft fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re 