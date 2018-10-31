p6: main.o maze.o djset.o
	g++ -o p6 main.o maze.o djset.o

main.o: main.cpp maze.h
	g++ -c -std=c++11 main.cpp

maze.o: maze.cpp maze.h djset.h
	g++ -c -std=c++11 maze.cpp

djset.o: djset.cpp djset.h
	g++ -c djset.cpp

clean:
	rm -f *.o *~
