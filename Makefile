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

HEIGHT = 	$(shell xdpyinfo | awk '/dimensions/{print $$2}' | cut -d 'x' -f1)

WIDTH = 	$(shell xdpyinfo | awk '/dimensions/{print $$2}' | cut -d 'x' -f2)

CFLAGS =	-Wall -Wextra -Werror -D HEIGHT=$(HEIGHT) -D WIDTH=$(WIDTH)

DEBUG =		-Wall -Wextra -Werror -g -D HEIGHT=$(HEIGHT) -D WIDTH=$(WIDTH)

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

FT_INC	= 		-I $(LIBDIR)/header

LIBFT = 		$(LIBDIR)/libft.a

LIBRARIES = 	$(LIBFT) $(MLX_LNK)

INCLUDES = 		$(FT_INC) $(MLX_INC)

################################################################################
################################## SRCS & OBJS #################################
################################################################################
ifeq ($(uname_S), Linux)
	SRCS =		$(SRCDIR)cub3d.c		\
				$(SRCDIR)cub3d_def.c	\
				$(SRCDIR)cub3d_linux.c	\

endif
ifeq ($(uname_S), Darwin)
	SRCS =		$(SRCDIR)cub3d.c		\
				$(SRCDIR)cub3d_def.c	\
				$(SRCDIR)cub3d_mac.c	\
				

endif

################################################################################
#################################### PROGRAM ###################################
################################################################################

EXEC =		cub3D

VAL =		valgrind -s --track-fds=yes --track-origins=yes --leak-check=full --leak-check=full --show-leak-kinds=all --show-reachable=yes

RUN =		./cub3D fake.cub

################################################################################
################################### COLOURS ####################################
################################################################################

GREEN = 	\033[0;32m

RED =		\033[0;31m

RESET = 	\033[0m

################################################################################
#################################### RULES #####################################
################################################################################

$(EXEC): $(LIBFT)
	$(MAKE) all -C $(MINILIBX_DIRECTORY);\
	$(CC) $(CFLAGS) $(SRCS) $(LIBRARIES) -I $(HEADER) -o $(EXEC)

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
	

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(EXEC)

clean_all: fclean
	$(MAKE) clean -C $(MINILIBX_DIRECTORY)


re: fclean all

debug: re $(LIBFT)
	$(MAKE) all -C $(MINILIBX_DIRECTORY);\
	$(CC) $(DEBUG) $(SRCS) $(LIBRARIES) -I $(HEADER) -o $(EXEC)

test: debug
	$(VAL) $(RUN)