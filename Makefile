# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaugero <afaugerou@42.fr>                    +#+  +:+       +#+      #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 14:40:40 by afaugero          #+#    #+#              #
#    Updated: 2025/01/10 18:37:10 by afaugero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
INCLUDES = includes

SRC = ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_strlen \
		ft_toupper \
		ft_tolower \
		ft_strncmp \
		ft_atoi \
		ft_memcmp \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strdup \
		ft_strndup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_strnstr \
		ft_itoa \
		ft_strmapi \
		ft_split \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_bzero \
		ft_striteri \
		ft_putnbr_fd \
		ft_memset \
		ft_memcpy \
		ft_memchr \
		ft_calloc \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap \
		printf/printf \
		printf/parsers	\
		printf/parse_hex \
		get_next_line \

SRCS = $(addsuffix .c, ${SRC})

OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} $(CFLAGS) -c $< -o $@ -I ${INCLUDES}

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

