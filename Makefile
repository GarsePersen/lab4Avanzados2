FLAGS= -g -Wall -std=c99

all: lab4

lab4: trie.o lab4.o lista.o archivo.o
	gcc $(FLAGS) trie.o lista.o archivo.o lab4.o -o lab4

lista.o: lista.h lista.c
	gcc $(FLAGS) -c lista.c -o lista.o

archivo.o: archivo.h archivo.c
	gcc $(FLAGS) -c archivo.c -o archivo.o

trie.o: trie.h trie.c
	gcc $(FLAGS) -c trie.c -o trie.o

clean:
	rm -f *.o lab_1.exe lab_1
