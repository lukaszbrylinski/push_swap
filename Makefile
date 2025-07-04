# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I includes -I libft

# Executable Name
NAME = push_swap

# Source Files (all .c files in the current directory)
SRCS = algorithm_utils.c \
		main.c \
		parsing.c \
		push.c \
		rotate.c \
		rotate2.c \
		sorting.c \
		swap.c \
		utils.c \
		printf.c \
		printf_utils.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Libft
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_LNK = -L$(LIBFT_DIR) -lft

# Default target
all: $(LIBFT_LIB) $(NAME)

# Build executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LNK)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build Libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Remove executables and object files
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re