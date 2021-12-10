output: chip8.o main.o
	g++ main.o chip8.o -o output

target: dependencies
	action