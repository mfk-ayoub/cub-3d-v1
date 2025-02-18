
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I$(minilibx_src) -g3 -g

minilibx_src = ./minilibx-linux/
minilibx = $(minilibx_src)libmlx_Linux.a

LIBS = -L$(minilibx_src) -lmlx_Linux -lXext -lX11 -lm -lz

BINDIR = bin
DIRS = . parser src assistants

SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
OBJ = $(patsubst %.c, $(BINDIR)/%.o, $(notdir $(SRC)))

vpath %.c $(DIRS)

all: $(minilibx) $(NAME)

$(NAME): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)

$(minilibx):
	make -C $(minilibx_src)

$(BINDIR):
	mkdir -p $(BINDIR)


$(BINDIR)/%.o: %.c | $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR)
	make -C $(minilibx_src) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
