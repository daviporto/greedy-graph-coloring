CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/vertex.o $(OBJ)/graph.o $(OBJ)/sorter.o
HDRS = $(INC)/vertex.h $(INC)/graph.h $(INC)/sorter.h
CFLAGS = -Wall -c -g -I$(INC) -std=c++11

EXE = $(BIN)/tp2.out

.PHONY: all clean

run: all
	$(EXE)

all: $(EXE)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -std=c++11 -g -o $(BIN)/tp2.out $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

$(OBJ)/vertex.o: $(HDRS) $(SRC)/vertex.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/vertex.o $(SRC)/vertex.cpp

$(OBJ)/sorter.o: $(HDRS) $(SRC)/sorter.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sorter.o $(SRC)/sorter.cpp


clean:
	rm -f $(EXE) $(OBJS) gmon.out