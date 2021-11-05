CC = g++

all: hw09

hw09: hw09.h hw09.cpp hw09f.o hw09f1.o hw09f2.o hw09f3.o hw09f4.o hw09f5.o
	$(CC) hw09.cpp -o hw09 hw09f.o hw09f1.o hw09f2.o hw09f3.o hw09f4.o hw09f5.o -fsanitize=address

hw09f.o: hw09.h hw09f.cpp
	$(CC) -c hw09f.cpp -o hw09f.o

hw09f1.o: hw09.h hw09f1.cpp
	$(CC) -c hw09f1.cpp -o hw09f1.o

hw09f2.o: hw09.h hw09f2.cpp
	$(CC) -c hw09f2.cpp -o hw09f2.o

hw09f3.o: hw09.h hw09f3.cpp
	$(CC) -c hw09f3.cpp -o hw09f3.o

hw09f4.o: hw09.h hw09f4.cpp
	$(CC) -c hw09f4.cpp -o hw09f4.o

hw09f5.o: hw09.h hw09f5.cpp
	$(CC) -c hw09f5.cpp -o hw09f5.o

clean:
	rm hw09 *.o *.tar

tar:
	tar cfv hw09.tar hw09.h hw09.cpp hw09f.cpp hw09f1.cpp hw09f2.cpp hw09f3.cpp hw09f4.cpp hw09f5.cpp
