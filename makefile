CC = g++
CFLAGS = -static-libgcc -static-libstdc++

SRCDIR = .
EXPRESSIONSDIR = expressions
SRC = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(EXPRESSIONSDIR)/*.cpp)
OBJ = $(SRC:.cpp=.o)

Tyr: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	del /Q $(SRCDIR)\*.o $(EXPRESSIONSDIR)\*.o

%.o: %.cpp
	$(CC) -c -o $@ $<