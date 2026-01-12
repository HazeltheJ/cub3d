# var
NAME		= cub3d
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -lbsd -lXext -lX11 -lm

# path
LIBFT_DIR	= includes/libft
MLX_DIR		= minilibx-linux
SRC_DIR		= src
INC_DIR		= includes

# src
SRCS		= \
			main.c \
			$(SRC_DIR)/parsing/init_struct.c \
			$(SRC_DIR)/parsing/read_map.c \
			$(SRC_DIR)/parsing/check_map.c \
			$(SRC_DIR)/utils/free.c \



	


# lib
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

# objects
OBJS		= $(SRCS:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re