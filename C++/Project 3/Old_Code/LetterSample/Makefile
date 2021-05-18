all: main 

main : LetterSample.o main.o LetterSample.h 
	g++ -o main LetterSample.o main.cpp 
	@echo Compiled! 

main.o : main.cpp LetterSample.h 
	g++ -c main.cpp

LetterSample.o : LetterSample.cpp LetterSample.h
	g++ -c LetterSample.cpp

clean :
	rm -f *.o main