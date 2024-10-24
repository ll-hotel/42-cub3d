CC = cc

INC_DIR = include
OBJ_DIR = .obj
SRC_DIR = src
LFT_DIR = libft
MLX_DIR = minilibx-linux

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I${INC_DIR} -I${LFT_DIR} -I${MLX_DIR}
DFLAGS = -MMD -MP
LFLAGS = -L${LFT_DIR} -lft -L${MLX_DIR} -lmlx_Linux -lXext -lX11 -lm

ifneq ("${DEBUG}", "")
	CFLAGS := ${DEBUG} ${CFLAGS}
endif

FILES = cube_utils.c \
	   event.c \
	   ft_str_endswith.c \
	   img_put_pixel.c \
	   img_put_line.c \
	   init.c \
	   main.c \
	   minimap.c \
	   moving.c \
	   parsing.c \
	   parsing_utils.c \
	   parsing_textures.c \
	   parsing_colours.c \
	   parse_rgb.c \
	   parsing_map.c \
	   parsing_grid_values_check.c \
	   parsing_grid_stretch_lines.c \
	   parsing_grid_wall_check.c \
	   ray.c \
	   read_file.c \
	   render.c \
	   render_texture.c \
	   vec2f.c \
	   wall_collision.c
OBJS = $(FILES:%.c=${OBJ_DIR}/%.o)

BONUS_DIR = bonus
BONUS_FILES = minimap.c wall_collision.c

DEPS = $(OBJS:.o=.d)

LIB_FT = ${LFT_DIR}/libft.a
LIB_MLX = ${MLX_DIR}/libmlx_Linux.a

NAME = cub3D

.PHONY: all
all: ${NAME}

-include ${DEPS}

${NAME}: ${OBJS} | ${LIB_FT} ${LIB_MLX}
	${CC} ${CFLAGS} ${IFLAGS} ${DFLAGS} -o $@ ${OBJS} ${LFLAGS}

${LIB_FT}::
	@make --no-print-directory -C ${LFT_DIR}

${LIB_MLX}:
	@make --no-print-directory -C ${MLX_DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${IFLAGS} ${DFLAGS} -o $@ -c $<

${OBJ_DIR}:
	mkdir -p $(sort $(dir ${OBJS}))

.PHONY: bonus
bonus:
ifeq ("$(wildcard ${OBJ_DIR}/${BONUS_DIR})","")
	mkdir -p ${OBJ_DIR}/${BONUS_DIR}
endif
	@make --no-print-directory FILES="$(filter-out ${BONUS_FILES},${FILES}) $(BONUS_FILES:%=${BONUS_DIR}/%)"

.PHONY: clean
clean:
	@make --no-print-directory -C ${MLX_DIR} clean
	@make --no-print-directory -C ${LFT_DIR} clean
	rm -rf ${OBJ_DIR}

.PHONY: fclean
fclean: clean
	@make --no-print-directory -C ${LFT_DIR} fclean
	rm -f ${NAME}

.PHONY: re
re: fclean
	@make --no-print-directory
