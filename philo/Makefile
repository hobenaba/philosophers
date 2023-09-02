CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = philo
 
MAINDATORY = action.c args.c init.c utils.c philo.c 

OBJS = $(MAINDATORY:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\033[0;35m your philo is compiling ...\033[0;0m"
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[0;32m all clean\033[0;0m"

re : fclean all

.SILENT : $(OBJS)