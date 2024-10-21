CC = cc

SRC_DIR = src
INC_DIR = include
OBJ_DIR = .obj

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I.
DFLAGS = -MMD -MP

OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, \
	   ft_basics/ft_atoi.c \
	   ft_basics/ft_bzero.c \
	   ft_basics/ft_calloc.c \
	   ft_basics/ft_isalnum.c \
	   ft_basics/ft_isalpha.c \
	   ft_basics/ft_isascii.c \
	   ft_basics/ft_isdigit.c \
	   ft_basics/ft_isprint.c \
	   ft_basics/ft_itoa.c \
	   ft_basics/ft_itoa_base.c \
	   ft_basics/ft_log_b.c \
	   ft_basics/ft_memchr.c \
	   ft_basics/ft_memcmp.c \
	   ft_basics/ft_memcpy.c \
	   ft_basics/ft_memmove.c \
	   ft_basics/ft_memset.c \
	   ft_basics/ft_putchar_fd.c \
	   ft_basics/ft_putendl_fd.c \
	   ft_basics/ft_putnbr_fd.c \
	   ft_basics/ft_putstr.c \
	   ft_basics/ft_putstr_fd.c \
	   ft_basics/ft_split.c \
	   ft_basics/ft_strchr.c \
	   ft_basics/ft_strdup.c \
	   ft_basics/ft_striteri.c \
	   ft_basics/ft_strjoin.c \
	   ft_basics/ft_strlcat.c \
	   ft_basics/ft_strlcpy.c \
	   ft_basics/ft_strlen.c \
	   ft_basics/ft_strmapi.c \
	   ft_basics/ft_strncmp.c \
	   ft_basics/ft_strnstr.c \
	   ft_basics/ft_strrchr.c \
	   ft_basics/ft_strtrim.c \
	   ft_basics/ft_substr.c \
	   ft_basics/ft_tolower.c \
	   ft_basics/ft_toupper.c \
	   ft_basics/ft_utoa.c \
	   ft_basics/ft_abs.c \
	   ft_basics/ft_max.c \
	   ft_basics/ft_min.c \
	   ft_basics/ft_limit.c \
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
	   ft_vec/vec_at.c \
	   ft_vec/vec_clear.c \
	   ft_vec/vec_new.c \
	   ft_vec/vec_addback.c \
	   ft_lst/lst_at.c \
	   ft_lst/lst_clear.c \
	   ft_lst/lst_delone.c \
	   ft_lst/lst_get_last.c \
	   ft_lst/lst_iter.c \
	   ft_lst/lst_len.c \
	   ft_lst/lst_map.c \
	   ft_lst/lst_next.c \
	   ft_ptr/ft_realloc.c \
	   ft_ptr/ft_free2.c \
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
