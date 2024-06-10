CC = cc
CFLAGS =  -Wall -Werror -Wextra #-fsanitize=address
MLXFLAGS =  -Lmlx -lmlx -framework OpenGL -framework AppKit 
NAME = fractol
SRC = $(wildcard src/*.c ) 
OBJS = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) 
		$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -O3 -o $(NAME) 

%.o: %.c inc/fractol.h
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

re: fclean all

fclean: clean
	rm -f $(NAME)

re:	fclean all 