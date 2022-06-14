all:
	gcc -Wall -g cliente.c arvore.c main.c -o executavel

run:
	./executavel

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./executavel