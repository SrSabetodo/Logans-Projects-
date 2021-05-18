all: main 

main : StringBag.o main.o StringBag.h 
	g++ -o main StringBag.o main.cpp 
	@echo Compiled! 

main.o : main.cpp StringBag.h 
	g++ -c main.cpp

StringBag.o : StringBag.cpp StringBag.h
	g++ -c StringBag.cpp

clean :
	rm -f *.o main