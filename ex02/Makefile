# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rficht <rficht@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 16:02:30 by rficht            #+#    #+#              #
#    Updated: 2024/01/06 10:31:44 by rficht           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

#-----------------------#
#	Makefile program	#
#-----------------------#

#avoid inheriting variables from the environement
SHELL = /bin/sh

#--- Program name ---#
NAME = exercice02

#--- LIBS ---#
#--- Includes ---#

# Compil flags
FLAGS = -Wall -Wextra -Werror

# General compilation flags
CFLAG = $(FLAGS)  $(INCLUDES) -std=c++98 -fsanitize=address -static-libasan
 
# Linking compilation flags
GFLAG = -g3

#---------------#
#	Sources		#
#---------------#
FILES +=	main.cpp\
			AForm.cpp\
			Bureaucrat.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp 

			

SOURCES = $(FILES)
OBJ = $(FILES:.cpp=.o)

# Compiler used for this project
CC = g++

# main rule called by default
all: $(NAME)

# rule for compile .c -> .o
%.o : %.cpp
	@printf '$(GREEN)Compiling: $(RESET)$@\n'
	@$(CC) $(CFLAG) -o $@ -c $<


# create the program
$(NAME): $(OBJ)
	@printf '$(RED)Linking: $(RESET)$@\n'
	$(CC) $(CFLAG) $(GFLAG) -o $(NAME) $(OBJ);
	
# remove .o corresponding to sources
clean:
	@printf ' -- cleaning objects $(NAME) -- \n'
	@rm -f $(OBJ)

# remove .o and .a corresponding to sources
fclean: clean
	@printf ' -- cleaning program $(NAME) -- \n'
	@rm -f $(NAME)

# force to recompile everything
re: fclean all

#help:
#	@echo 'Sources:'
#	@echo $(SOURCES)

#target: dependencies
#		recipies
# $@ target name
# $< first dependencie
# $^ dependencies list
# $? dependencies that ar more recent than target