CC = g++
CFLAGS = -static-libgcc -static-libstdc++

SRC = Norse.cpp parser.cpp
OBJ = $(SRC:.cpp=.o)

Norse: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo Compiled $(SRC)

%.o: %.cpp
	$(CC) -c -o $@ $<

clean:
	del -f Norse $(OBJ)

.PHONY: all clean