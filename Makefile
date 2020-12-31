all: isort txtfind

isort: mainPartA.c
	gcc -Wall -g -o isort mainPartA.c 

txtfind: mainPartB.c
	gcc -Wall -g -o txtfind mainPartB.c

clean: isort txtfind

.PHONY: all clean



