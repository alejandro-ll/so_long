NAME = so_long
SRCS_DIR = ./src
UTILS_DIR = ./utils
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/read_map.c $(SRCS_DIR)/init_graphics.c $(SRCS_DIR)/open_images_map.c $(SRCS_DIR)/draw_map.c $(SRCS_DIR)/char_functions.c $(SRCS_DIR)/hook_loader.c $(SRCS_DIR)/open_images_map_two.c $(SRCS_DIR)/pick_coin.c $(SRCS_DIR)/exit_object.c $(UTILS_DIR)/set_tile_size.c $(UTILS_DIR)/set_window_size.c $(UTILS_DIR)/check_map.c $(UTILS_DIR)/check_map_two.c $(UTILS_DIR)/check_solution.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm
GNL_DIR = ./get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re