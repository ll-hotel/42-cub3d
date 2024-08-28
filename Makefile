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

OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, \
	   init.c \
	   main.c \
	   parsing.c \
	   parsing_utils.c \
	   parsing_textures.c \
	   parsing_colours.c \
	   parsing_map.c \
	   parsing_grid_values_check.c \
	   parsing_grid_stretch_lines.c \
	   parsing_grid_wall_check.c \
	   read_file.c \
	   cube_utils.c \
	   ft_str_endswith.c \
	   \
	   event.c \
	   event_player.c \
	   render.c \
	   minimap.c \
	   img_put_pixel.c \
	   img_put_line.c \
	   ray.c \
	   \
	   vec2f.c \
	   )
DEPS = ${OBJS:.o=.d}
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
