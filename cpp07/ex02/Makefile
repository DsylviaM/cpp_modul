NAME	=	ex02
SRCS	=	main.cpp
INCLUDE	=	Array.hpp, Array.tpp
OBJS	=	$(SRCS:.cpp=.o)
CC		= 	c++
RM		=	rm -rf
FLAGS	=	-Wall -Wextra -Werror
STD	=	-std=c++98

all:		$(NAME)

${NAME} : ${OBJS} 
	${CC} -g ${OBJS} -o ${NAME} 

%.o : %.cpp ${INCLUDE}
	${CC} -g ${STD} ${FLAGS} -c $< -o $@

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
