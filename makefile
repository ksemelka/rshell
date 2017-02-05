CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic --std=c++11
EXEC=rshell.exe
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

all: 
	cd src && $(MAKE)
	$(CC) -c $(CC_FLAGS) $< -o $@
rshell:

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
