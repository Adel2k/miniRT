# NAME = miniRT


# SRCS_DIR = sources /
# INC_DIR = include /
# MLX_DIR = minilibx-linux
# GNL = gnl

# CC = cc
# # INCLUDE = -I$(INC_DIR) -I$(MLX_DIR)/include -I$(GNL)
# CFLAGS = -Wall -Wextra -Werror -I mlx -g3 -fsanitize=address
# MLXFLAGS = -lmlx -framework OpenGL -framework AppKit 

# HEADERS = 	include/miniRT.h include/get_next_line.h
# SOURCES = miniRT.c 

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $^ -o $@ $(MLXFLAGS)

# $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
# 	@mkdir -p $(OBJS_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@ 

# clean:
# 	@$(RM) $(OBJS)

# fclean: clean
# 	@$(RM) $(NAME)
# 	rm -rf $(OBJS_DIR)

# re: fclean all

# .PHONY: all clean fclean re




NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -I mlx #-g3 -fsanitize=address
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADERS = include/get_next_line.h include/minirt.h

SRCS_DIR = sources/

OBJS_DIR = objs/

SRCS_NAME = minirt.c \
			get_next_line.c \
			get_next_line_utils.c \

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re