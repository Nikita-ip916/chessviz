CC = gcc
CFLAGS = -Wall -Werror -c
OUT = out
DIR = build
DIR2 = bin
F = -o
all:
		$(CC) $(F) $(DIR)/main.o $(CFLAGS) src/main.c
		$(CC) $(F) $(DIR)/board_fill_plain.o $(CFLAGS) src/board_fill_plain.c
		$(CC) $(F) $(DIR)/board_print_plain.o $(CFLAGS) src/board_print_plain.c
		$(CC) $(F) $(DIR)/board_read.o $(CFLAGS) src/board_read.c
		$(CC) $(F) $(DIR)/board.o $(CFLAGS) src/board.c
		$(CC) $(DIR)/*.o -o $(DIR2)/$(OUT)
clean:
		rm -rf $(DIR2)/$(OUT) $(DIR)/*.o
