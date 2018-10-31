p2: main.o Heap.o
	g++ -o p2 main.o Heap.o

main.o: main.cpp Heap.h
	g++ -c main.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

clean: 
	rm -f *.o *~
