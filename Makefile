CC = gcc
CFLAGS = -Wall -Werror -c
all:
		$(CC) $(CFLAGS) src/main.c
		$(CC) $(CFLAGS) src/board_fill_plain.c
		$(CC) $(CFLAGS) src/board_print_plain.c
		$(CC) main.o board_fill_plain.o board_print_plain.o -o deposit-calc
clean:
		rm -rf *.o *.exe
