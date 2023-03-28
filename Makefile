# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:26:53 by msintas-          #+#    #+#              #
#    Updated: 2023/03/23 11:52:54 by msintas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol

SRCS	=	main.c fractol.c complex.c coloring.c mandelbrot.c julia.c \
			check_argus.c utils.c interactions.c

BONUS	=	burningship_bonus.c check_argus_bonus.c fractol_bonus.c \
			main_bonus.c complex_bonus.c coloring_bonus.c mandelbrot_bonus.c \
			julia_bonus.c utils_bonus.c interactions_bonus.c

CC		=	gcc

CFLAGS	=   -Wextra -Wall -Werror 

RM		=	rm -rf

LIBFT	=	./Libs/libft

MLX42	=	./Libs/mlx42

INCLUDES	=	-I include -I $(MLX42)/include/MLX42

LIBS	=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(MLX42)/libmlx42.a $(LIBFT)/libft.a

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(MLX42)
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
			@make -C $(LIBFT) clean
			@make -C $(MLX42) clean
			$(RM) $(OBJS) $(BOBJS)

fclean:		
			@make -C $(MLX42) clean
			@make -C $(LIBFT) fclean
			$(RM) $(OBJS) $(BOBJS) $(NAME)

re:			fclean all

bonus:		$(BOBJS)
			@make -C $(MLX42)
			@make -C $(LIBFT) --silent
			$(CC) $(CFLAGS) $(BOBJS) $(INCLUDES) $(LIBS) -o $(NAME)

run : all
	./$(NAME)

.PHONY:		all clean fclean re mlx42 bonus
