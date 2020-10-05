all: main

main: main.o ItemType.o DoublyLinkedList.o
	g++ main.o ItemType.o DoublyLinkedList.o -o main

main.o: main.cpp
	g++ -c main.cpp

ItemType.o: ItemType.cpp
	g++ -c ItemType.cpp

SortedLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp

clean:
	rm ItemType.o main.o DoublyLinkedList.o main
