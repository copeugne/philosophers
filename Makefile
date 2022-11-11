
################################################################################
#                                     CONFIG                                   #
################################################################################

ifndef VERBOSE
# MAKEFLAGS += --no-print-directory --silent
endif

AUTHOR	= copeugne

NAME				=	philo
PROJECT_NAME		=	philosophers

################################################################################
#                                 SOURCES                                      #
################################################################################
SOURCES_FOLDER				=	./src/
INCLUDES_FOLDER				=	./inc/
OBJECTS_FOLDER				=	./objs/
TESTS_FOLDERS				=	./tests/

SOURCES :=	main.c			\
			error.c			\
			helpers_atoi.c	\
			helpers_time.c	\
			parsing.c		\
			init_threads.c	\
			terminate.c		\
			routines.c		\
			subroutines.c	\
			mutex.c			\
			helpers_end.c	\



################################################################################
#                                  OBJETS                                      #
################################################################################

OBJECTS		 	= $(SOURCES:.c=.o)
OBJECTS			:= $(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES			:= $(addprefix $(SOURCES_FOLDER),$(SOURCES))
DEPS		 	= $(OBJECTS:.o=.d)

################################################################################
#                                  FLAGS                                       #
################################################################################

# FSANITIZE		=	-g3 -fsanitize=thread
#FLAGS			=	$(FSANITIZE)
# FLAGS			=	-MMD -Wall -Wextra -Werror -pthread $(FSANITIZE)
FLAGS			=	-Wall -Wextra -Werror -g -pthread
CC				=	clang
INCLUDES		=	-I$(INCLUDES_FOLDER)

################################################################################
#                                 COLORS                                       #
################################################################################

NO_COLOR 		=	\033[38;5;15m
OK_COLOR		=	\033[38;5;2m
ERROR_COLOR		=	\033[38;5;1m
WARN_COLOR		=	\033[38;5;3m
SILENT_COLOR	=	\033[38;5;245m
INFO_COLOR		=	\033[38;5;140m
OBJ_COLOR		=	\033[0;36m

################################################################################
#                                 RULES                                        #
################################################################################

all: $(NAME)

-include $(DEPS)
malloc_test: $(OBJECTS)
	$(CC) $(FLAGS) -fsanitize=undefined -rdynamic -o $@ $(OBJECTS) $(INCLUDES) -L. -lmallocator

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(INCLUDES)

-include $(DEPS)
$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -rf $(OBJECTS_FOLDER)

norm:
	norminette ${SOURCES_FOLDER} ${INCLUDES_FOLDER}

doclean: all clean

debug: FLAGS += -g
debug: fclean $(NAME)

re: fclean all

.PHONY: all re clean fclean force doclean norm header test bonus
