all: main 

main : SentenceSample.o main.o SentenceSample.h 
	g++ -o main SentenceSample.o main.cpp 
	@echo Compiled! 

main.o : main.cpp SentenceSample.h 
	g++ -c main.cpp

SentenceSample.o : SentenceSample.cpp SentenceSample.h
	g++ -c SentenceSample.cpp

clean :
	rm -f *.o main