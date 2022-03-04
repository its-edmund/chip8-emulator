CC = g++

CFLAGS = -std=c++20 -g -Wall -Wextra\
         -Wstrict-prototypes -Wold-style-definition

all: main run clean

main:
	$(CC) $(CFLAGS) main.cpp -o main -I include -L lib -l SDL2-2.0.0

run:
	./main

clean:
	rm main