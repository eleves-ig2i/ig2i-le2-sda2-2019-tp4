all : tp4.exe

tp4.exe : tp4.o AVL.o testAVL.o util.o
	gcc tp4.o AVL.o testAVL.o util.o -o tp4.exe

tp4.o :	tp4.c
	gcc -c tp4.c -o tp4.o

AVL.o : AVL.c
	gcc -c AVL.c -o AVL.o

testAVL.o : testAVL.c
	gcc -c testAVL.c -o testAVL.o

util.o : util.c
	gcc -c util.c -o util.o
clean :
	rm -f *.o *.exe
