NAME		= account_test

ORIGINAL	= 19920104_091532.log
THIS_OUT	= a.log
THAT_OUT	= b.log

GCC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES	= Account.cpp tests.cpp
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
	rm -f ${THIS_OUT}
	rm -f ${THAT_OUT}


re: fclean all


test:
	./${NAME} > ./aux_${THAT_OUT}
	cp ./${ORIGINAL} ./aux_${THIS_OUT}
	sed "s/^\[[0-9_]*\] //" ./aux_${THIS_OUT} > ./${THIS_OUT}
	rm ./aux_${THIS_OUT}
	sed "s/^\[[0-9_]*\] //" ./aux_${THAT_OUT} > ./${THAT_OUT}
	rm ./aux_${THAT_OUT}
	diff ./${THIS_OUT} ./${THAT_OUT}


.PHONY: all, clean, fclean, re, test
