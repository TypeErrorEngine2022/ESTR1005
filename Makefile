all:
	gcc -o game gameoflife.c render.c logic.c -lSDL2