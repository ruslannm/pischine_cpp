BIN = diamondtrap

CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

CPP = $(wildcard *.cpp)
OBJ = $(CPP:%.cpp=%.o)
DEP = $(OBJ:%.o=%.d)
$(BIN) : $(OBJ)
	$(CXX) $(CXX_FLAGS) $^ -o $@

-include $(DEP)

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) -MMD -c $< -o $@

.PHONY: all re clean fclean
clean :
	rm -f $(OBJ) $(DEP)
fclean: clean
	rm -f $(BIN)

re: fclean all
