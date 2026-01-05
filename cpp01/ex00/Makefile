NAME		= brains

GCC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES	= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ_FILES	= $(SRC_FILES:.cpp=.o)


all: ${NAME}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.cpp)
%.o: %.cpp
	${GCC} ${FLAGS} -c $< -o $@


${NAME}: ${OBJ_FILES}
	${GCC} ${FLAGS} ${OBJ_FILES} -o ${NAME}


clean:
	rm -f ${OBJ_FILES}


fclean: clean
	rm -f ${NAME}


re: fclean all


.PHONY: all, clean, fclean, re
