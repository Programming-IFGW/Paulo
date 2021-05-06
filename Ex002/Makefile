# Makefile

# Name of the project
PROJ_NAME=main
 
# .cpp files
C_SOURCE=$(wildcard *.cpp)
 
# .h files
H_SOURCE=$(wildcard *.h)
 
# Object files
OBJ=$(C_SOURCE:.cpp=.o)
 
# Compiler
CC=g++
 
# Flags for compiler
CC_FLAGS= -c -W -Wall -ansi -pedantic 
OTHER_FLAGS= -pthread -std=c++17 -m64 

# Compilation and linking
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(OTHER_FLAGS) 
 
%.o: %.cpp %.h
 
	$(CC) -o $@ $< $(CC_FLAGS) $(OTHER_FLAGS)
 
main.o: main.cpp $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS) $(OTHER_FLAGS)
 
clean:
	 rm -rf *.o *~

