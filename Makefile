# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 15:42:46 by rpaparon          #+#    #+#              #
#    Updated: 2025/03/05 16:14:49 by rpaparon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = sources/*.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
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

$(NAME): $(OBJECTS) $(LIBFT)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

$(NAME_BONUS): $(OBJECTS_BONUS) $(LIBFT)
	@echo "$(CYAN)Linking $(NAME_BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)✔ $(NAME_BONUS) compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

re: fclean all

banner:
	@echo "$(CYAN)############################################################$(RESET)"
	@echo "$(CYAN)#─────────────────▄█──────────█─────────█▄─────────────────#$(RESET)"
	@echo "$(CYAN)#───────────────▐██──────▄█──███──█▄─────██▌───────────────#$(RESET)"
	@echo "$(CYAN)#──────────────▐██▀─────█████████████────▀██▌──────────────#$(RESET)"
	@echo "$(CYAN)#─────────────▐██▌─────██████████████─────▐██▌─────────────#$(RESET)"
	@echo "$(CYAN)#─────────────████────████████████████────████─────────────#$(RESET)"
	@echo "$(CYAN)#────────────▐█████──██████████████████──█████▌────────────#$(RESET)"
	@echo "$(CYAN)#─────────────████████████████████████████████─────────────#$(RESET)"
	@echo "$(CYAN)#──────────────███████▀▀████████████▀▀███████──────────────#$(RESET)"
	@echo "$(CYAN)#───────────────█████▌──▄▄─▀████▀─▄▄──▐█████───────────────#$(RESET)"
	@echo "$(CYAN)#─────────────▄▄██████▄─▀▀──████──▀▀─▄██████▄▄─────────────#$(RESET)"
	@echo "$(CYAN)#───────────██████████████████████████████████─────────────#$(RESET)"
	@echo "$(CYAN)#───────────████████████████████████████████████───────────#$(RESET)"
	@echo "$(CYAN)#──────────▐██████──███████▀▄██▄▀███████──██████▌──────────#$(RESET)"
	@echo "$(CYAN)#──────────▐█████────██████████████████────█████▌──────────#$(RESET)"
	@echo "$(CYAN)#──────────▐█████─────██████▀──▀██████─────█████▌──────────#$(RESET)"
	@echo "$(CYAN)#───────────█████▄─────███────────███─────▄█████───────────#$(RESET)"
	@echo "$(CYAN)#────────────██████─────█──────────█─────██████────────────#$(RESET)"
	@echo "$(CYAN)#──────────────█████────────────────────█████──────────────#$(RESET)"
	@echo "$(CYAN)#───────────────█████──────SO_LONG─────█████───────────────#$(RESET)"
	@echo "$(CYAN)#────────────────█████────────────────█████────────────────#$(RESET)"
	@echo "$(CYAN)#─────────────────████───▄────────▄───████─────────────────#$(RESET)"
	@echo "$(CYAN)#──────────────────████─██────────██─████──────────────────#$(RESET)"
	@echo "$(CYAN)#──────────────────████████─▄██▄─████████──────────────────#$(RESET)"
	@echo "$(CYAN)#─────────────────████████████████████████─────────────────#$(RESET)"
	@echo "$(CYAN)#─────────────────████████████████████████─────────────────#$(RESET)"
	@echo "$(CYAN)#──────────────────▀█████████▀▀█████████▀──────────────────#$(RESET)"
	@echo "$(CYAN)#────────────────────▀███▀────────▀███▀────────────────────#$(RESET)"
	@echo "$(CYAN)############################################################$(RESET)"


