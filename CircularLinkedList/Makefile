all: main

main: main.o ItemType.o CircularLinkedList.o
	g++ main.o ItemType.o CircularLinkedList.o -o main

main.o: main.cpp
	g++ -c main.cpp

ItemType.o: ItemType.cpp
	g++ -c ItemType.cpp

CircularLinkedList.o: CircularLinkedList.cpp
	g++ -c CircularLinkedList.cpp

clean:
	rm ItemType.o main.o CircularLinkedList.o main
