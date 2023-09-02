CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus
 
BONUS =  philo_bonus.c args_bonus.c action_bonus.c utils_bonus.c init_bonus.c

OBJS_BONUS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_BONUS)
	@echo "\033[0;35m your philo_bonus is compiling ...\033[0;0m"
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) 

clean :
	@rm -rf $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[0;32m all clean\033[0;0m"

re : fclean all

.SILENT : $(OBJS_BONUS)