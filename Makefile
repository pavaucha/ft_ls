NAME = ft_ls

CC = gcc

CFLAGS = -Werror -Wextra -Wall

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft

LDLIBS = -lftprintf

SRC_NAME = main.c \
	ft_sort_affiche.c \
	ft_ascii.c \
	ft_del_list.c \
	ft_recursive_ls.c \
	ft_start_recursive.c \
	ft_aff_del_file.c \
	ft_recu_a.c \
	ft_keep_l.c \
	ft_uitoa.c \
	ft_padding_str.c \
	ft_strnew_c.c \
	ft_take_time.c \
	ft_block_octet.c \
	ft_sort_t.c \
	ft_free_list.c \
	ft_flags.c \
	ft_swap_t.c \
	ft_nb_list.c \
	ft_initialize_list.c \
	ft_affiche_l.c \
	ft_uid_grp.c

SRC_PATH = ./sources
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./sources
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir ./objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)
	@rm -rf ./objs
fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
