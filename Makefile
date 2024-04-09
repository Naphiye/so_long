NAME = so_long
COMPIL = cc
FLAGS = -Wall -Werror -Wextra 
PINK = \033[1;35m
BLUE = \033[1;36m
NC = \033[0m

HEADER_F = so_long.h

COMMON_SRCS = common_close.c \
			common_free.c \
			common_init.c \
			common_parsing.c \
			common_parsing2.c \
			common_search_path.c \
			common_search_path2.c \
			common_utils.c 

MANDATORY_SRCS = game.c \
				init_game.c \
				main.c \
				move.c \
				player_action.c \
				search_path.c 


BONUS_SRCS = bonus.c \
			game_bonus.c \
			init_game_bonus.c \
			main_bonus.c \
			move_bonus.c \
			player_action_bonus.c \
			search_path_bonus.c \
			wall_animations_bonus.c 

# Magic with srcs and objs #

PMANDATORY = $(addprefix srcs/mandatory/, $(MANDATORY_SRCS)) $(addprefix srcs/common/, $(COMMON_SRCS)) 
PBONUS = $(addprefix srcs/bonus/, $(BONUS_SRCS)) $(addprefix srcs/common/, $(COMMON_SRCS))
B_OBJS = $(PBONUS:srcs/%.c=objs/%.o)
M_OBJS = $(PMANDATORY:srcs/%.c=objs/%.o)

LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a \
		minilibx-linux/libmlx.a

all : $(NAME) 

$(LIBFT): 
	@make -sC libft 
	@make bonus -sC libft 
	@echo  "$(PINK)\n     LIBFT COMPILED \n$(NC)"

$(MLX):
	@make -sC minilibx-linux
	
objs/%.o: srcs/%.c $(HEADER_F)
	@mkdir -p objs/common objs/mandatory objs/bonus
	@$(COMPIL) $(FLAGS) -I/usr/include -I./ -Iminilibx-linux -c $< -o $@

$(NAME) : $(M_OBJS) $(HEADER_F) $(LIBFT) $(MLX)
	@$(COMPIL) $(FLAGS) -o $@ $(M_OBJS) $(LIBFT) -L/usr/lib -I./ -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz 
	@echo  "$(BLUE)\n     SO_LONG COMPILED \n$(NC)"


bonus : $(B_OBJS) $(HEADER_F) $(LIBFT) $(MLX)
	@$(COMPIL) $(FLAGS) -o $(NAME) $(B_OBJS) $(LIBFT) -L/usr/lib -I./ -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz 
	@echo  "$(BLUE)\n     SO_LONG COMPILED \n$(NC)"

clean :
	@rm -rf objs/*
	@make -sC libft clean
	@make -sC minilibx-linux clean
	@echo  "$(PINK) \n     LIBFT CLEANED  \n$(NC)"
	@echo  "$(BLUE) \n     SO_LONG CLEANED \n$(NC)"

fclean : clean
	@rm -f $(NAME) 
	@make -sC libft fclean

re : fclean all

.PHONY : all clean fclean re bonus