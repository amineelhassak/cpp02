SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC =	BSP

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all