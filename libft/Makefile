CC := cc

SRC_DIR := src
INC_DIR := include
OBJ_DIR := .obj

CFLAGS := -Wall -Wextra -Werror
IFLAGS := -Iinclude -Iinclude/libft
DFLAGS := -MMD -MP

OBJS := $(patsubst %.c,${OBJ_DIR}/%.o, \
	   core/ft_atoi.c \
	   core/ft_bzero.c \
	   core/ft_calloc.c \
	   core/ft_isalnum.c \
	   core/ft_isalpha.c \
	   core/ft_isascii.c \
	   core/ft_isdigit.c \
	   core/ft_isprint.c \
	   core/ft_itoa.c \
	   core/ft_itoa_base.c \
	   core/ft_log_b.c \
	   core/ft_memchr.c \
	   core/ft_memcmp.c \
	   core/ft_memcpy.c \
	   core/ft_memmove.c \
	   core/ft_memset.c \
	   core/ft_putchar_fd.c \
	   core/ft_putendl_fd.c \
	   core/ft_putnbr_fd.c \
	   core/ft_putstr.c \
	   core/ft_putstr_fd.c \
	   core/ft_split.c \
	   core/ft_strchr.c \
	   core/ft_strdup.c \
	   core/ft_striteri.c \
	   core/ft_strjoin.c \
	   core/ft_strlcat.c \
	   core/ft_strlcpy.c \
	   core/ft_strlen.c \
	   core/ft_strmapi.c \
	   core/ft_strncmp.c \
	   core/ft_strnstr.c \
	   core/ft_strrchr.c \
	   core/ft_strtrim.c \
	   core/ft_substr.c \
	   core/ft_tolower.c \
	   core/ft_toupper.c \
	   core/ft_utoa.c \
	   core/ft_abs.c \
	   core/ft_max.c \
	   core/ft_min.c \
	   core/ft_limit.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \
	   ft_dprintf/src/dprintf.c \
	   ft_dprintf/src/dprintf_ascii.c \
	   ft_dprintf/src/dprintf_atoi32.c \
	   ft_dprintf/src/dprintf_atoi64.c \
	   ft_dprintf/src/dprintf_buffer.c \
	   ft_dprintf/src/dprintf_utils.c \
	   ft_dprintf/src/dprintf_specifier.c \
	   ft_printf/ft_printf.c \
	   ft_printf/ft_printf_handlers.c \
	   ft_printf/ft_printf_xtoa.c \
	   vec/vec_at.c \
	   vec/vec_clear.c \
	   vec/vec_new.c \
	   vec/vec_addback.c \
	   lst/lst_at.c \
	   lst/lst_clear.c \
	   lst/lst_delone.c \
	   lst/lst_get_last.c \
	   lst/lst_iter.c \
	   lst/lst_len.c \
	   lst/lst_map.c \
	   lst/lst_next.c \
	   ptr/ft_realloc.c \
	   ptr/ft_free2.c \
	   )
DEPS = ${OBJS:.o=.d}

NAME = libft.a

.PHONY: all
all: ${NAME}

-include ${DEPS}

.SILENT: ${NAME}
${NAME}: ${OBJS}
	ar -rc $@ ${OBJS}
	echo 'Libft compiled'

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${IFLAGS} ${DFLAGS} -o $@ -c $<

${OBJ_DIR}:
	mkdir -p $(sort $(dir ${OBJS}))

.PHONY: clean
clean:
	rm -rf ${OBJ_DIR}

.PHONY: fclean
fclean: clean
	rm -f ${NAME}

.SILENT: re
.PHONY: re
re: fclean
	make --no-print-directory
