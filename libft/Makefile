# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbetz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/12 14:39:25 by bbetz             #+#    #+#              #
#    Updated: 2016/09/06 10:45:02 by bbetz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Main
NAME	=	libft.a
AR		=	ar -rcs
CC		=	gcc

ifeq ($(DEBUG), yes)
FDEBUG	=	-Wextra -Wall -Werror
endif

WFLAGS	=	-Wall -Wextra -Werror -g
OPTI	=	-I
LS		=	ls -1
GREP	=	grep
MKDIR	=	mkdir -p
RM		=	rm -rf

# Directory
DSRC	=	sources
DOBJ	=	objets
DINC	=	include

# File
FSRC	:=	$(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ	:=	$(FSRC:.c=.o)

# Transform
FSRC	:=	$(addprefix $(DSRC)/, $(FSRC))
FOBJ	:=	$(addprefix $(DOBJ)/, $(FOBJ))
FINC	:=	$(addprefix $(OPTI) , $(DINC))

all: $(FOBJ) $(NAME)

$(NAME): $(FOBJ)
	$(AR) $@ $(FOBJ)

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	$(MKDIR) $(DOBJ)
	$(CC) $(FDEBUG) $(WFLAGS) -c $< $(FINC) -o $@

clean:
	$(RM) $(DOBJ)

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all begin clean fclean r
