CC=g++
CFLAGS= -Wall -O2

main: main.o menu.o oblicz.o file.o
	$(CC) $(CFLAGS) -o main main.o menu.o oblicz.o file.o 

main.o: main.cpp
	$(CC) -c main.cpp

menu.o: menu.cpp
	$(CC) -c menu.cpp

oblicz.o: oblicz.cpp
	$(CC) -c oblicz.cpp

file.o: file.cpp
	$(CC) -c file.cpp

docs:
	@doxygen
	@open html/index.html

clean:
	rm *.o main file.txt

