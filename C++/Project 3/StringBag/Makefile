all: main

main : StringBag.o main.o StringBag.h
	g++ -g -o main StringBag.o main.cpp
	@echo Compiled!

main.o : main.cpp StringBag.h
	g++ -c -g main.cpp

StringBag.o : StringBag.cpp StringBag.h
	g++ -c -g StringBag.cpp

clean :
	rm -f *.o main