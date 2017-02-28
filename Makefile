# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbetz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/14 19:46:58 by bbetz             #+#    #+#              #
#    Updated: 2017/02/27 14:49:42 by bbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
EXTRA_FLAGS		= 
OPTI			= -I

LS      		= ls -1
GREP			= grep
MKDIR			= mkdir -p
RM				= rm -rf

SRC_PATH		= sources
LIB_PATH		= libft
INC_PATH		= include
INC_LIB_PATH	= include \
							$(LIB_PATH)/include
DOBJ			= objets

SRC_FILES		:= $(shell $(LS) $(SRC_PATH) | $(GREP) .c$)
OBJ_FILES		:= $(SRC_FILES:.c=.o)
LIBFT			:= libft.a

SRC_FILES		:= $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ_FILES		:= $(addprefix $(DOBJ)/, $(OBJ_FILES))
FINCLIB			:= $(addprefix $(OPTI) , $(INC_LIB_PATH))
LIBFT			:= $(addprefix $(LIB_PATH)/, $(LIBFT))

all: libft $(OBJ_FILES) $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ_FILES) $(LIBFT) -lncurses -o $@

$(DOBJ)/%.o: $(SRC_PATH)/%.c $(INC_PATH)
	@$(MKDIR) $(DOBJ)
	$(CC) $(CFLAGS) -c $< $(FINCLIB) -o $@

libft:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) clean
	$(RM) $(DOBJ)

fclean: clean
	make -C $(LIB_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
