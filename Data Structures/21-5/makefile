p5: main.o hashTable.o
	g++ -o p5 main.o hashTable.o

main.o: main.cpp hashTable.h
	g++ -c -std=c++11 main.cpp

hashTable.o: hashTable.cpp hashTable.h
	g++ -c -std=c++11 hashTable.cpp

clean:
	rm -f *.o *~
