# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 12:43:01 by imisumi           #+#    #+#              #
#    Updated: 2023/11/21 20:49:43 by imisumi-wsl      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

# CFLAGS = -Wall -Werror -Wextra
CFLAGS = -I$(INCDIR)

ifdef DEBUG
CFLAGS += -g -O0
BUILDMSG = "Built $(NAME) in debug mode"
else
BUILDMSG = "Built $(NAME)"
endif


SRCDIR		:= src
INCDIR		:= include
OBJDIR		:= .obj

SOURCES		:= $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)
OBJECTS		:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

RED=\033[1;31m
PINK=\033[1;35m
CYAN=\033[1;36m
GREEN=\033[0;32m
NC=\033[0m

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo "$(GREEN)Building c object $@$(NC)"

$(NAME): $(OBJECTS)
#	@echo "$(PINK)[Creating libary: libft]$(NC)"
	@ar -r $(NAME) $(OBJECTS) >/dev/null 2>&1
	@echo "$(CYAN)Building libary $@$(NC)"

all: $(NAME)
	@echo "$(PINK)$(BUILDMSG)$(NC)"

clean:
	@if test -d $(OBJDIR); then \
		rm -rf $(OBJDIR); \
		echo "$(RED)Deleting object$(NC)"; \
	else \
		echo "clean: Nothing to be done"; \
	fi

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Deleting $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re
