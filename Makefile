CC = gcc
CFLAGS = -Wall -Werror -c
OUT = chessviz
DIR = build
DIR2 = bin
DIR3 = src
DIR4 = test
PRT = -I src -I thirdparty
F = -o
all:
		$(CC) $(F) $(DIR)/$(DIR3)/main.o $(CFLAGS) $(DIR3)/main.c
		$(CC) $(F) $(DIR)/$(DIR3)/board_fill_plain.o $(CFLAGS) $(DIR3)/board_fill_plain.c
		$(CC) $(F) $(DIR)/$(DIR3)/board_print_plain.o $(CFLAGS) $(DIR3)/board_print_plain.c
		$(CC) $(F) $(DIR)/$(DIR3)/board_read.o $(CFLAGS) $(DIR3)/board_read.c
		$(CC) $(F) $(DIR)/$(DIR3)/board.o $(CFLAGS) $(DIR3)/board.c
		$(CC) $(PRT) $(CFLAGS) $(DIR4)/main.c $(F) $(DIR)/$(DIR4)/main.o
		$(CC) $(PRT) $(CFLAGS) $(DIR4)/board_test.c $(F) $(DIR)/$(DIR4)/board_test.o
		$(CC) $(DIR)/$(DIR3)/*.o -o $(DIR2)/$(OUT)
		$(CC) $(DIR)/$(DIR3)/board*.o $(DIR)/$(DIR4)/*.o -o $(DIR2)/$(OUT)-$(DIR4)
clean:
		rm -rf $(DIR2)/chessviz* $(DIR)/$(DIR3)/*.o $(DIR)/$(DIR4)/*.o
