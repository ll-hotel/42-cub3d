MAKEFLAGS := -j

MAKE := make
CC := clang
RM := rm -f
CPPFLAGS := -MMD -MP
CFLAGS := -Wall -Wextra -Werror -Iinclude
LDFLAGS :=
LDLIBS := -lm -lX11 -lXext

NAME := cub3D
OBJ_DIR := .obj
SRC_DIR := src
SRCS := \
	src/main.c \
	src/render.c \
	src/parsing_grid_wall_check.c \
	src/init.c \
	src/parsing.c \
	src/parsing_grid_values_check.c \
	src/mouse_tracking.c \
	src/cube_utils.c \
	src/wall_collision.c \
	src/event.c \
	src/img_put_pixel.c \
	src/ray.c \
	src/vec2f.c \
	src/moving.c \
	src/img_put_line.c \
	src/ft_str_endswith.c \
	src/parse_rgb.c \
	src/render_texture.c \
	src/parsing_grid_stretch_lines.c \
	src/minimap.c \
	src/parsing_colours.c \
	src/parsing_textures.c \
	src/read_file.c \
	src/parsing_utils.c \
	src/parsing_map.c \
	src/mouse.c
SRCS_BONUS := \
	src/bonus/wall_collision.c \
	src/bonus/minimap.c \
	src/bonus/mouse.c \

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(patsubst %.o,%.d,$(OBJS))

LIB_MLX := minilibx-linux/libmlx.a
CFLAGS += -I$(dir $(LIB_MLX))
LDFLAGS += -L$(dir $(LIB_MLX))
LDLIBS += -l$(patsubst lib%.a,%,$(notdir $(LIB_MLX)))

LIB_FT := libft/libft.a
CFLAGS += -I$(dir $(LIB_FT))
LDFLAGS += -L$(dir $(LIB_FT))
LDLIBS += -l$(patsubst lib%.a,%,$(notdir $(LIB_FT)))

all: $(NAME)

$(NAME): $(OBJS) | $(LIB_MLX) $(LIB_FT)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

%.a:
	@$(MAKE) -C $(dir $@)

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
	@$(MAKE) --no-print-directory $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re %.a
