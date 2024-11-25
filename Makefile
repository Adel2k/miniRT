NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -I mlx -g3 -fsanitize=address
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm


HEADERS = include/get_next_line.h include/minirt.h include/mlx.h

SRCS_DIR = sources/

OBJS_DIR = objects/

SRCS_NAME = minirt.c \
			get_next_line.c \
			get_next_line_utils.c \
			validation.c \
			utils.c utils2.c\
			exit_free.c \
			split.c split_char.c\
			trim.c \
			parsing.c init_func.c\
			init_mlx.c \
			parsing_utils.c \
			atof.c \
			key_hooks.c \
			ft_lst_func.c \
			scene.c vector.c ray_tracing_2.c init_mlx.c \
			compute_light.c plane_inter.c cylinder_inter.c matrix.c \
			move_and_rottate.c figure_rotate.c sphere_intersect.c \
			color_functions.c

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