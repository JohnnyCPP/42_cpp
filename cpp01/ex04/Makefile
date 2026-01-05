NAME			= sed_is_for_losers

GCC				= c++
FLAGS			= -Wall -Wextra -Werror -std=c++98
SANITIZE_FLAGS	= -fsanitize=address

SRC_FILES		= main.cpp
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
	rm -f test.txt
	rm -f test.txt.replace


re: fclean all


sanitize: fclean ${OBJ_FILES}
	${GCC} ${FLAGS} ${SANITIZE_FLAGS} ${OBJ_FILES} -o ${NAME}


test: all
	@echo "=== Creating test files ==="
	@echo "Hello World! This is a test file." > test.txt
	@echo "It contains multiple lines." >> test.txt
	@echo "Hello again! Hello Hello." >> test.txt
	@echo "=== Running sed_is_for_losers ==="
	./$(NAME) test.txt "Hello" "Goodbye"
	@echo "=== Original file ==="
	@cat test.txt
	@echo -e "\n=== Modified file ==="
	@cat test.txt.replace
	@echo -e "\n=== Testing edge cases ==="
	./$(NAME) test.txt "World" "Universe"
	@echo "=== Testing empty s1 ==="
	./$(NAME) test.txt "" "something" || true


.PHONY: all, clean, fclean, re, sanitize, test
