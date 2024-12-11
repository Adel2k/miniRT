NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -I mlx #-g3 -fsanitize=address
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

HEADERS = include/get_next_line.h include/minirt.h include/mlx.h

SRCS_DIR = sources/

OBJS_DIR = objects/

SRCS_NAME = minirt.c \
			get_next_line.c \
			get_next_line_utils.c \
			validation.c \
			validation_utils.c \
			add_texture.c \
			atof.c \
			utils.c \
			free_exit.c \
			split.c split_char.c\
			trim.c \
			parsing.c init_func.c\
			init_mlx.c \
			parsing_utils.c \
			color.c \
			draw_utils.c \
			init_utils.c \
			key_hooks.c \
			list_utils.c \
			texture_utils.c \
			add_texture.c \
			vector.c ray_tracing.c init_mlx.c \
			compute_light.c plane_inter.c cylinder.c matrix.c \
			move_and_rottate.c figure_rotate.c sphere_inter.c \
			shadow.c light_utils.c \
			checkerboard.c \
			list_func.c free_objs.c vector_utils.c rotation.c\

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