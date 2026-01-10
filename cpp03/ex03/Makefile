NAME			= repetitiveWorkTwo

GCC				= c++
# because the exercise asks to intentionally create shadowing
SHADOWING		= -Wno-shadow
FLAGS			= -Wall -Wextra -Werror ${SHADOWING} -std=c++98
SANITIZE_FLAGS	= -fsanitize=address

SRC_FILES		= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJ_FILES		= $(SRC_FILES:.cpp=.o)


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


sanitize: fclean ${OBJ_FILES}
	${GCC} ${FLAGS} ${SANITIZE_FLAGS} ${OBJ_FILES} -o ${NAME}


.PHONY: all, clean, fclean, re, sanitize
