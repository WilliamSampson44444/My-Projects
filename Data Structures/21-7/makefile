p7: main.o bstree.o
	g++ -o p7 main.o bstree.o

main.o: main.cpp bstree.h
	g++ -c -std=c++11 main.cpp

bstree.o: bstree.cpp bstree.h
	g++ -c -std=c++11 bstree.cpp

clean:
	rm -f *.o *~
