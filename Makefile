NAME=pipex
FLAGS=-Wall -Wextra -Werror -I includes/ -I libft/includes -I ft_printf/includes -g3
LIBFT=libft/libft.a
FT_PRINTF=ft_printf/libftprintf.a
LIBSFLAGS=-L libft/ -lft -L ft_printf/ -lftprintf
SRCSF=main.c init.c check_args.c parse_cmds.c parse_files.c ft_exec.c
OBJSF=$(SRCSF:.c=.o)
SRCDIR=srcs/
OBJDIR=objs/
SRCS=$(addprefix srcs/, $(SRCSF))
OBJS=$(addprefix objs/, $(OBJSF))

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@make -C libft/ bonus

$(FT_PRINTF):
	@make -C ft_printf/

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJS)
	@echo "\033[0m\033[1;35m|\033[0m"
	@mv $(OBJSF) $(OBJDIR)
	@gcc $(LIBFT) $(FT_PRINTF) $(FLAGS) -o $(NAME) $(OBJS) $(LIBSFLAGS)
	@echo "\033[1;32mpipex ready ✓\033[0m"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo " \c"
	@gcc $(FLAGS) -c $^

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "\033[1;35mpipex compiling... |\033[0m\033[45m\c"

clean:
	@rm -rf $(OBJDIR)
	@echo "\033[1;31mpipex objects deleted\033[0m"
	@make -C libft clean
	@echo "\033[1;31mlibft objects deleted\033[0m"
	@make -C ft_printf clean
	@echo "\033[1;31mft_printf objects deleted\033[0m"


fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31mpipex binary file deleted\033[0m"
	@make -C libft/ fclean
	@make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re