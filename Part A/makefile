# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp Person.cpp Secretary.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
EXEC = myprogram

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)
