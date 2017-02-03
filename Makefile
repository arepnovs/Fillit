
NAME = fillit

FLAG =	-Wall -Wextra -Werror 

SRC =	main.c\
		check.c\
		ft_arr_putstr.c\
		ft_memalloc.c\
		ft_putendl.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strndup.c\
		ft_strnew.c\
		ft_strsplit.c\
		put_data_in_tetr.c\
		solve.c\
		solve_tools.c\

SRO  =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@echo "Compiling Fillit"
		@gcc $(FLAG) -c $(SRC)
		@gcc $(FLAG) -o $(NAME) $(SRC)
		@echo "Fillit is ready"
clean:
	@rm -f *.o
	@echo "Objects successfully removed"
fclean:	
	@make clean
	@rm -f $(NAME)
	@echo "Executable successfully removed"

re: 
	@make fclean
	@make all
