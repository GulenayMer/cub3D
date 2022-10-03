uname_S := $(shell uname -s)

ifeq ($(uname_S), Linux)
	MINILIBX_DIRECTORY = ./minilibx_linux/
	MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
	MLX_INC	= -I minilibx_linux
	MLX_LNK	= -Lminilibx_linux -lm -lmlx -lXext -lX11 -Iminilibx-linux
endif
ifeq ($(uname_S), Darwin)
	MINILIBX_DIRECTORY = ./minilibx_macos/
	MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
	MLX_INC	= -I minilibx_macos
	MLX_LNK	= -Lminilibx_macos -lm -lmlx -framework OpenGL -framework AppKit -Iminilibx_macos
endif

################################################################################
################################ COMPILER & FLAGS ##############################
################################################################################

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror 

DEBUG =		-Wall -Wextra -Werror -g

VAL =		valgrind -s --leak-check=full --show-leak-kinds=all

################################################################################
################################## DIRECTORIES #################################
################################################################################

HEADER = 	./header

OBJDIR =	 build/

LIBDIR = 	libft

SRCDIR =	src/

################################################################################
################################### LIBRARIES ##################################
################################################################################

FT_INC	= 		-I ../libft/header

LIBFT = 		$(LIBDIR)/libft.a

LIBRARIES = 	$(LIBFT) $(MLX_LNK)

INCLUDES = 		$(FT_INC) $(MLX_INC)

################################################################################
################################## SRCS & OBJS #################################
################################################################################
ifeq ($(uname_S), Linux)
	SRCS :=		cub3D.c		\
				

endif
ifeq ($(uname_S), Darwin)
	SRCS :=		cub3D.c		\
				

endif

OBJS :=		${SRCS:.c=.o}

OBJ_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))

################################################################################
#################################### PROGRAM ###################################
################################################################################

EXEC =		cub3D

RUN =		./cub3D

################################################################################
################################### COLOURS ####################################
################################################################################

GREEN = 	\033[0;32m

RED =		\033[0;31m

RESET = 	\033[0m

################################################################################
#################################### RULES #####################################
################################################################################

$(EXEC): $(LIBFT) $(OBJ_PREFIXED)
	$(MAKE) all -C $(MINILIBX_DIRECTORY)
	$(CC) $(CFLAGS) $(OBJ_PREFIXED) $(LIBRARIES) -I $(HEADER) -o $(EXEC)

$(OBJ_PREFIXED): build/%.o : src/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(FT_INC) -c $< -o $@ 

$(LIBFT):
	$(MAKE) all -C $(LIBDIR)

all: $(EXEC) 

objdir:
	mkdir -p $(OBJDIR)

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(MAKE) clean -C $(MINILIBX_DIRECTORY)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -rf $(OBJDIR)
	rm -f $(EXEC)
	rm -f $(CHECKER)

re: fclean all
