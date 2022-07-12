CC = g++
LFLAGS = -o
CFLAGS = -c -g -Wall -Werror
IFLAG = -I$(INC)
INC = ./inc
BIN = ./bin
OBJ = ./obj
SRC = ./src

all: app valgrind

app: $(OBJ)/EmpsysPrg.o
	$(CC) $(LFLAGS) $(BIN)/EmpsysPrg $(OBJ)/EmpsysPrg.o
	mv app $(BIN)


$(OBJ)/EmpsysPrg.o: $(SRC)/EmpsysPrg.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/EmpsysPrg.cpp 
	mv EmpsysPrg.o $(OBJ)

valgrind:
	valgrind --leak-check=full $(BIN)./app

clean:
	rm -f a.out EmpsysPrg
	rm -f *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/app

