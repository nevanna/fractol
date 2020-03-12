# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htillman <htillman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 17:08:23 by htillman          #+#    #+#              #
#    Updated: 2019/03/06 16:49:32 by htillman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
#
SRC = main.c ft_put.c ft_try_draw.c thr_spider.c thr_julia.c thr_mandel.c \
	ft_fractols.c thr_br_sh.c ft_k.c ft_kk.c ft_kkk.c ft_pid.c ft_lambda.c thr_drop.c \
	ft_fractols_s.c
FILESO = ${SRC:.c=.o}
FILESO = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror
LIBA = -L ./libft -lft
MIN = -L ./minilibx_macos -lmlx
ADD = -framework OpenGL -framework AppKit
INCL = -I ./libft
INCLM = -I ./minilibx_macos

all: $(NAME)

$(NAME): $(FILESO)
	make -C ./libft/
	make -C ./minilibx_macos/
	gcc  $(FLAGS) -o $(NAME) $(SRC) $(LIBA) $(MIN) $(ADD)

%.o: %.c
	#$(FLAGS)
	gcc  $(INCL)  -o $@ -c $<

clean:
	rm -f $(FILESO)
	make clean -C ./libft/
	make clean -C ./minilibx_macos/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all
