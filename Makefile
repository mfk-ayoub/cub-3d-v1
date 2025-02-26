
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror  -I./includes -I/usr/local/lib -I./include/ -g3 -g



LIBS = -lmlx_Linux -lXext -lX11 -lm -lz

BINDIR = bin
DIRS = . parser src assistants

SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJ = $(patsubst %.c, $(BINDIR)/%.o, $(notdir $(SRC)))

vpath %.c $(DIRS)

all: $(NAME)

$(NAME): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)


$(BINDIR):
	mkdir -p $(BINDIR)


$(BINDIR)/%.o: %.c | $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR)
	

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
