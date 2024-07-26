CC = cc

INC_DIR = include
OBJ_DIR = .obj
SRC_DIR = src
LFT_DIR = libft
MLX_DIR = minilibx-linux

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I${INC_DIR} -I${MLX_DIR}
DFLAGS = -MMD -MP
LFLAGS = -L${LFT_DIR} -L${MLX_DIR} -lft -lmlx

OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, \
	   main.c \
	   )
DEPS = ${OBJS:.o=.d}
LIB_FT = ${LFT_DIR}/libft.a
LIB_MLX = ${MLX_DIR}/libmlx_Linux.a

NAME = cub3D

.PHONY: all
all: ${NAME}

${NAME}: ${OBJS} | ${LIB_FT} ${LIB_MLX}
	${CC} ${CFLAGS} ${IFLAGS} ${DFLAGS} -o $@ ${OBJS} ${LFLAGS}

${LIB_FT}:
	@make --no-print-directory -C ${LFT_DIR}

${LIB_MLX}:
	@make --no-print-directory -C ${MLX_DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${IFLAGS} ${DFLAGS} -o $@ -c $<

${OBJ_DIR}:
	mkdir -p $(sort $(dir ${OBJS}))

.PHONY: clean
clean:
	rm -rf ${OBJ_DIR}
	@make --no-print-directory -C ${MLX_DIR} clean
	@make --no-print-directory -C ${LFT_DIR} clean

.PHONY: fclean
fclean: clean
	rm -f ${NAME}
	@make --no-print-directory -C ${LFT_DIR} fclean

.PHONY: re
re: fclean
	@make --no-print-directory
