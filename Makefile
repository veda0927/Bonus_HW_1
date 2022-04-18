SRC_FILENAME = shell.c
BIN_FILENAME = uab_sh

all: $(PROGRAM)
	gcc -g -O0 -Wall -o $(BIN_FILENAME) $(SRC_FILENAME)

clean:
	rm -rfv $(BIN_FILENAME)
