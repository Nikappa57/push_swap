# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 14:47:54 by mcerchi           #+#    #+#              #
#    Updated: 2023/03/23 23:14:24 by lorenzogaud      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	push_swap
NAME_BONUS				=	checker

INCLUDES				=	-I includes -I $(LIBFT_DIR)/includes/

LIBFT					=	$(LIBFT_DIR)libft.a
LIBFT_DIR				=	libft/
LIB_FLAGS				=	-L $(LIBFT_DIR) -lft

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror
RM						=	/bin/rm -f
NORM					=	norminette

DIR_SRCS				=	srcs
DIR_OBJS				=	objs
DIR_OBJS_BONUS			=	objs_bonus
SUBDIRS					=	push_swap sort actions utils
SUBDIRS_BONUS			=	checker sort actions utils

SRCS_PATHS				=	$(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_PATHS				=	$(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS					=	$(foreach dir, $(SRCS_PATHS), $(wildcard $(dir)/*.c))
OBJS					=	$(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

SRCS_PATHS_BONUS		=	$(foreach dir, $(SUBDIRS_BONUS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_PATHS_BONUS		=	$(foreach dir, $(SUBDIRS_BONUS), $(addprefix $(DIR_OBJS_BONUS)/, $(dir)))
SRCS_BONUS				=	$(foreach dir, $(SRCS_PATHS_BONUS), $(wildcard $(dir)/*.c))
OBJS_BONUS				=	$(subst $(DIR_SRCS), $(DIR_OBJS_BONUS), $(SRCS_BONUS:.c=.o))

$(DIR_OBJS)/%.o :		$(DIR_SRCS)/%.c
						mkdir -p $(DIR_OBJS) $(OBJS_PATHS)
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS_BONUS)/%.o :	$(DIR_SRCS)/%.c
						mkdir -p $(DIR_OBJS_BONUS) $(OBJS_PATHS_BONUS)
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:					$(NAME)

bonus:					$(NAME_BONUS)

$(LIBFT):
						make -C $(LIBFT_DIR)

$(NAME):				$(OBJS) $(LIBFT)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

$(NAME_BONUS):			$(OBJS_BONUS) $(LIBFT)
						$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB_FLAGS)

clean:
						make clean -C $(LIBFT_DIR)
						${RM} $(OBJS) $(OBJS_BONUS)
						$(RM) -r $(DIR_OBJS) $(DIR_OBJS_BONUS)

fclean:					clean
						make fclean -C $(LIBFT_DIR)
						$(RM) $(NAME) $(NAME_BONUS)

re:						fclean all

norm:
						$(NORM) */*.h */*/*.c

.PHONY:					all clean fclean re bonus norm