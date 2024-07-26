CC = cc

SRC_DIR = src
INC_DIR = include
OBJ_DIR = .obj

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I. -I${INC_DIR}
DFLAGS = -MMD -MP

OBJS = $(patsubst %.c,${OBJ_DIR}/%.o,\
	   basics/ft_atoi.c \
	   basics/ft_bzero.c \
	   basics/ft_calloc.c \
	   basics/ft_isalnum.c \
	   basics/ft_isalpha.c \
	   basics/ft_isascii.c \
	   basics/ft_isdigit.c \
	   basics/ft_isprint.c \
	   basics/ft_itoa.c \
	   basics/ft_itoa_base.c \
	   basics/ft_log_b.c \
	   basics/ft_memchr.c \
	   basics/ft_memcmp.c \
	   basics/ft_memcpy.c \
	   basics/ft_memmove.c \
	   basics/ft_memset.c \
	   basics/ft_putchar_fd.c \
	   basics/ft_putendl_fd.c \
	   basics/ft_putnbr_fd.c \
	   basics/ft_putstr.c \
	   basics/ft_putstr_fd.c \
	   basics/ft_split.c \
	   basics/ft_strchr.c \
	   basics/ft_strdup.c \
	   basics/ft_striteri.c \
	   basics/ft_strjoin.c \
	   basics/ft_strlcat.c \
	   basics/ft_strlcpy.c \
	   basics/ft_strlen.c \
	   basics/ft_strmapi.c \
	   basics/ft_strncmp.c \
	   basics/ft_strnstr.c \
	   basics/ft_strrchr.c \
	   basics/ft_strtrim.c \
	   basics/ft_substr.c \
	   basics/ft_tolower.c \
	   basics/ft_toupper.c \
	   basics/ft_utoa.c \
	   ft_dprintf/src/dprintf.c \
	   ft_dprintf/src/dprintf_ascii.c \
	   ft_dprintf/src/dprintf_atoi32.c \
	   ft_dprintf/src/dprintf_atoi64.c \
	   ft_dprintf/src/dprintf_buffer.c \
	   ft_dprintf/src/dprintf_specifier.c \
	   ft_dprintf/src/dprintf_utils.c \
	   ft_printf/ft_printf.c \
	   ft_printf/ft_printf_handlers.c \
	   ft_printf/ft_printf_xtoa.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \
	   vector/vec_at.c \
	   vector/vec_clear.c \
	   vector/vec_new.c \
	   vector/vec_addback.c \
	   lst/lst_clear.c \
	   lst/lst_delone.c \
	   lst/lst_get_last.c \
	   lst/lst_len.c \
	   lst/lst_next.c \
	   lst/lst_at.c \
	   lst/lst_iter.c \
	   lst/lst_map.c \
	   ft_realloc.c \
	   fptr.c \
	   sptr.c \
	   max.c \
	   maxu.c \
	   maxf.c \
	   )
DEPS = ${OBJS:.o=.d}

NAME = libft.a

.PHONY: all
all: ${NAME}

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
