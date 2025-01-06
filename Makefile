MAKEFLAGS :=

MAKE := make
CC := cc
RM := rm -f
CPPFLAGS := -MMD -MP
CFLAGS := -Wall -Wextra -Werror -Iinclude -O2 -g
LDFLAGS :=
LDLIBS := -lm -lX11 -lXext

NAME := cub3D
OBJ_DIR := .obj
SRC_DIR := src
SRCS :=

SRCS += src/main.c
SRCS += src/s_cub.c
SRCS += src/s_img.c
SRCS += src/s_mlx.c
SRCS += src/hooks.c
SRCS += src/s_map.c
SRCS += src/parsing/ft_str_endswith.c
SRCS += src/parsing/parse_rgb.c
SRCS += src/parsing/parsing.c
SRCS += src/parsing/map_values_check.c
SRCS += src/parsing/map_wall_check.c
SRCS += src/parsing/colours.c
SRCS += src/parsing/textures.c
SRCS += src/parsing/utils.c
SRCS += src/parsing/map.c
SRCS += src/parsing/read_file.c

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(patsubst %.o,%.d,$(OBJS))

LIB_MLX := minilibx/libmlx.a
CFLAGS += -I$(dir $(LIB_MLX))
LDFLAGS += -L$(dir $(LIB_MLX))
LDLIBS += -l$(patsubst lib%.a,%,$(notdir $(LIB_MLX)))

LIB_FT := libft/libft.a
CFLAGS += -I$(dir $(LIB_FT))include
LDFLAGS += -L$(dir $(LIB_FT))
LDLIBS += -l$(patsubst lib%.a,%,$(notdir $(LIB_FT)))

all: norminette $(NAME)

norminette:
	@norminette $(SRC_DIR) include | grep -v 'OK' || echo 'Norm OK!'

$(NAME): $(LIB_MLX) $(LIB_FT) $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

$(LIB_MLX) $(LIB_FT)::
	@$(MAKE) --no-print-directory -C $(dir $@)

$(OBJ_DIR)/%.o: %
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

clean:
	@$(MAKE) -C $(dir $(LIB_FT)) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(dir $(LIB_MLX)) clean
	@$(MAKE) -C $(dir $(LIB_FT)) fclean
	$(RM) $(NAME)

re: fclean
	@$(MAKE) --no-print-directory

-include $(DEPS)

.PHONY: all clean fclean re
