NAME			= PmergeMe

GCC				= c++
FLAGS			= -Wall -Wextra -Werror -std=c++98
SANITIZE_FLAGS	= -fsanitize=address

HPP_FILES		= PmergeMe.hpp

SRC_FILES		= PmergeMe.cpp main.cpp
OBJ_FILES		= $(SRC_FILES:.cpp=.o)


all: ${NAME}


%.o: %.cpp ${HPP_FILES}
	${GCC} ${FLAGS} -c $< -o $@


${NAME}: ${OBJ_FILES}
	${GCC} ${FLAGS} ${OBJ_FILES} -o ${NAME}


clean:
	rm -f ${OBJ_FILES}


fclean: clean
	rm -f ${NAME}


re: fclean all


sanitize: fclean ${OBJ_FILES}
	${GCC} ${FLAGS} ${SANITIZE_FLAGS} ${OBJ_FILES} -o ${NAME}


.PHONY: all, clean, fclean, re, sanitize
