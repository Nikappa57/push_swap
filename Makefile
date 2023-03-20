# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 14:47:54 by mcerchi           #+#    #+#              #
#    Updated: 2023/03/20 14:34:22 by lorenzogaud      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	push_swap.c ft_print_utils.c ft_arg_parse.c ft_stack_utils.c \
				ft_action_swap.c ft_action_rotate.c ft_action_push.c ft_lis.c \
				ft_math_utils.c ft_push_to_a.c ft_action_utils.c ft_stack_action.c \
				ft_action_reverse_rotate.c ft_short_sort.c ft_simplify_stack.c \
				ft_stack_sort_utils.c ft_push_to_b.c ft_push_to_a_utils.c ft_chunk.c

SRC_BONUS	=	checker.c get_next_line.c get_next_line_utils.c ft_arg_parse.c \
				ft_stack_action.c ft_print_utils.c ft_stack_sort_utils.c \
				ft_stack_utils.c
				
LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

# CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re
