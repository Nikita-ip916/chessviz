CC = gcc
CFLAGS = -Wall -Werror
OUT = chessviz
PRT = -I src -I test -I thirdparty
HEADERS = src/board_fill_plain.h src/board_print_plain.h src/board_read.h src/board.h
.PHONY: all runprog clean test
all: bin/$(OUT)

bin/$(OUT): build/src/main.o build/src/board_fill_plain.o build/src/board_print_plain.o build/src/board_read.o build/src/board.o
		$(CC) build/src/main.o build/src/board_fill_plain.o build/src/board_print_plain.o build/src/board_read.o build/src/board.o -o $@

build/src/main.o: src/main.c $(HEADERS)
		$(CC) $(CFLAGS) -I src -c $< -o $@

build/src/board_fill_plain.o: src/board_fill_plain.c
		$(CC) $(CFLAGS) -I src -c $< -o $@

build/src/board_print_plain.o: src/board_print_plain.c
		$(CC) $(CFLAGS) -I src -c $< -o $@

build/src/board_read.o: src/board_read.c
		$(CC) $(CFLAGS) -I src -c $< -o $@

build/src/board.o: src/board.c
		$(CC) $(CFLAGS) -I src -c $< -o $@

bin/$(OUT)-test: build/src/board_fill_plain.o build/src/board_print_plain.o build/src/board_read.o build/src/board.o build/test/main.o build/test/board_test.o
		$(CC) build/src/board_fill_plain.o build/src/board_print_plain.o build/src/board_read.o build/src/board.o build/test/main.o build/test/board_test.o -o $@

build/test/main.o: test/main.c
		$(CC) $(CFLAGS) $(PRT) -c $< -o $@

build/test/board_test.o: test/board_test.c $(HEADERS)
		$(CC) $(CFLAGS) $(PRT) -c $< -o $@

runprog:
		./bin/$(OUT)

test: bin/$(OUT)-test
		./bin/chessviz-test
		echo "Все тесты пройдены!"

clean:
		rm -rf bin/chessviz* build/src/*.o build/test/*.o
