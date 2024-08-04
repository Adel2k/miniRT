NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -I mlx -g3 -fsanitize=address
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

HEADERS = include/get_next_line.h include/minirt.h include/mlx.h

SRCS_DIR = sources/

OBJS_DIR = objects/

SRCS_NAME = minirt.c \
			get_next_line.c \
			get_next_line_utils.c \
			validation.c \
			utils.c \
			error.c \
			split.c \
			trim.c \
			

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	rm -rf $(OBJS_DIR)

re: clean all

.PHONY: all clean fclean re