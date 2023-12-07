NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
PRINTF_OBJS = ${PRINTF_SRCS:.c=.o}
GNL_OBJS = ${GNL_SRCS:.c=.o}
SRCS = ft_strjoin.c\
	ft_atoi.c\
	ft_strlcat.c\
	ft_bzero.c\
	ft_strlcpy.c\
	ft_calloc.c\
	ft_memchr.c\
	ft_strlen.c\
	ft_isalnum.c\
	ft_isspace.c\
	ft_memcmp.c\
	ft_strmapi.c\
	ft_isalpha.c\
	ft_memcpy.c\
	ft_strncmp.c\
	ft_isascii.c\
	ft_memmove.c\
	ft_strnstr.c\
	ft_isdigit.c\
	ft_memset.c\
	ft_strrchr.c\
	ft_isprint.c\
	ft_putchar_fd.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_putendl_fd.c\
	ft_substr.c\
	ft_putnbr_fd.c\
	ft_tolower.c\
	ft_putstr_fd.c\
	ft_toupper.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c
BONUS_SRCS = ft_lstadd_back.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstsize.c\
	ft_lstadd_front.c\
	ft_lstdelone.c\
	ft_lstlast.c\
	ft_lstnew.c
PRINTF_SRCS = ft_printf.c\
	ft_hex_utils.c\
	ft_printf_utils.c\
	ft_num_utils.c\
	ft_format_utils.c
GNL_SRCS = get_next_line.c\
	get_next_line_utils.c

ifdef ADD_BONUS
ALL_OBJS = $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
else
ALL_OBJS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(ALL_OBJS)
	ar -rcs $(NAME) $(ALL_OBJS)

bonus:
	$(MAKE) ADD_BONUS=1

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re

test:
	cc libfttester.c libft.a && ./a.out