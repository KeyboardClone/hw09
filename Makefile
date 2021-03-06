CC = g++

all: hw09

hw09: hw09.h hw09.cpp hw09f.o hw09f1.o hw09f2.o hw09f3.o hw09f4.o hw09f5.o hw09f6.o hw09f7.o hw09f8.o hw09f9.o hw09f10.o hw09f11.o
	$(CC) hw09.cpp -o hw09 hw09f.o hw09f1.o hw09f2.o hw09f3.o hw09f4.o hw09f5.o hw09f6.o hw09f7.o hw09f8.o hw09f9.o hw09f10.o hw09f11.o -fsanitize=address

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

hw09f6.o: hw09.h hw09f6.cpp
	$(CC) -c hw09f6.cpp -o hw09f6.o

hw09f7.o: hw09.h hw09f7.cpp
	$(CC) -c hw09f7.cpp -o hw09f7.o

hw09f8.o: hw09.h hw09f8.cpp
	$(CC) -c hw09f8.cpp -o hw09f8.o

hw09f9.o: hw09.h hw09f9.cpp
	$(CC) -c hw09f9.cpp -o hw09f9.o

hw09f10.o: hw09.h hw09f10.cpp
	$(CC) -c hw09f10.cpp -o hw09f10.o

hw09f11.o: hw09.h hw09f11.cpp
	$(CC) -c hw09f11.cpp -o hw09f11.o

clean:
	rm hw09 *.o *.tar

tar:
	tar cfv hw09.tar hw09.h hw09.cpp hw09f.cpp hw09f1.cpp hw09f2.cpp hw09f3.cpp hw09f4.cpp hw09f5.cpp hw09f6.cpp hw09f7.cpp hw09f8.cpp hw09f9.cpp hw09f10.cpp hw09f11.cpp hw09.scr Makefile
