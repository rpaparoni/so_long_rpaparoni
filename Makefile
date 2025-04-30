# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 15:42:46 by rpaparon          #+#    #+#              #
#    Updated: 2025/04/30 13:49:03 by rpaparon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

SOURCES = sources/main.c \
		  sources/hooks.c \
		  sources/map.c \
		  sources/render.c \
		  sources/utils.c \
		  sources/msg.c \
		  
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I. -I$(LIBFT_DIR)

RM = rm -rf

GREEN  = \033[1;32m
RED    = \033[1;31m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RESET  = \033[0m
PURPLE = \033[1;35m

.PHONY: all clean fclean re

all: banner $(NAME)

bonus: banner $(NAME_BONUS)

$(NAME): $(OBJECTS) $(LIBFT) $(MLX)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX):
	@echo "$(BLUE)Compiling minilibx...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --silent

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

re: fclean all

banner:
	@echo "                   $(PURPLE)               o"
	@echo "                   O       /\`-.__"
	@echo "                          /  \\^'\|"
	@echo "             o           T    l  *"
	@echo "                        _|-..-|_"
	@echo "                 O    (^ '----' \`)"
	@echo "                       \`\\-....-/^"
	@echo "             O       o  ) \"/ \" ("
	@echo "                       _( (-)  )_"
	@echo "                   O  /\\ )    (  /\\"
	@echo "                     /  \\\(    ) |  \\\\"
	@echo "                 o  o    \\\)  ( /    \\\\"
	@echo "                   /     |(  )|      \\\\"
	@echo "                  /    o \\\ \\( /       \\\\"
	@echo "            __.--'   O    \\\_ /   .._   \\\\"
	@echo "           //|)\\      ,   (_)   /(((\\^)'\\\\"
	@echo "              |       | O         )  \`  |"
	@echo "              |      / o___      /      /"
	@echo "             /  _.-''^^__O_^^''-._     /"
	@echo "           .'  /  -''^^    ^^''-  \\\\--'^"
	@echo "         .'   .\`.  \`'''----'''^  .\`. \\\\"
	@echo "       .'    /   \`'--..____..--'^   \\\\ \\\\"
	@echo "      /  _.-/                        \\\\ \\\\"
	@echo "  .::'_/^   |                        |  \`."
	@echo "         .-'|                        |    \`-."
	@echo "   _.--'\`   \\\\                        /       \`-."
	@echo "  /          \\\\                      /           \`-._"
	@echo "  \`'---..__   \`.                  ._.._   __       \\\\"
	@echo "           \`\`'''\`.              .'SO_LONG^\`  \`''---'^"
	@echo "                  \`-..______..-'"
	@echo "$(RESET)"

