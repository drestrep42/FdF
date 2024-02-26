# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 19:54:56 by drestrep          #+#    #+#              #
#    Updated: 2024/02/25 20:18:42 by drestrep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		fdf

CC 				= 		gcc
CFLAGS 			= 		-g -g3 -Wall -Wextra -Werror -fsanitize=address

LIBRARIES		=		-lmlx -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
	
LIBFT_DIR		=		libft
LIBFT			=		$(LIBFT_DIR)/libft.a

MINILIBX_DIR	=		libmlx

SRC_DIR			=		src
SRCS			=		$(wildcard	src/*.c)

OBJ_DIR			=		obj
OBJS 			= 		$(addprefix obj/, $(notdir $(SRCS:%.c=%.o)))

all:					$(NAME)
	
$(NAME):				$(OBJS)  $(LIBFT) | $(OBJ_DIR)
						@$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES) -o fdf
						@echo " "
						@echo "🟥🟥🟥	🟩🟩	🟦🟦🟦"
						@echo "🟥	🟩  🟩	🟦"
						@echo "🟥🟥🟥	🟩  🟩	🟦🟦🟦"
						@echo "🟥	🟩  🟩	🟦"
						@echo "🟥	🟩🟩	🟦"
						@echo " "

	
$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c | $(OBJ_DIR)
						@$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT):	
						@make -C $(LIBFT_DIR)
	
$(OBJ_DIR):	
						@mkdir -p $(OBJ_DIR)
	
clean:	
						@make fclean -C $(LIBFT_DIR)
						@rm -rf $(OBJ_DIR)
	
fclean: clean	
						@rm -rf $(NAME)

re: fclean all
