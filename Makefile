CC=g++
CFLAGS=-Wall
LDFLAGS=
EXEC=PRPIP
recurfind = $(shell find $(1) -name '$(2)')
SRC=$(call recurfind,.,*.cpp)
# SRC=$(wildcard main.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

run: mrproper all
	@./$(EXEC)

$(EXEC): $(SRC)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
	@rm -rf $(TEXEC)
