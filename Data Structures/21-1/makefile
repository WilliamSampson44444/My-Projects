p1: main.o List.o LinkNode.o
	g++ -o p1 main.o List.o

main.o: main.cpp List.h
	g++ -c main.cpp

List.o: List.cpp List.h LinkNode.h
	g++ -c List.cpp

LinkNode.o: LinkNode.h
	g++ -c LinkNode.h

clean:
	rm -f *.o *~
