main: main.o LinkedList.o
	gcc -o main main.o LinkedList.o

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c -g LinkedList.c

main.o: main.c
	gcc -c -g main.c

clean:
	rm main LinkedList.o main.o
