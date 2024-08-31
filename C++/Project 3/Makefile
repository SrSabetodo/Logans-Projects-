# all: main

# main : Gibberisher.o main.o ../SentenceSample/SentenceSample.h ../StringBag/StringBag.h Gibberisher.h
# 	g++ -g -o main Gibberisher.o main.cpp
# 	@echo Compiled!

# main.o : main.cpp ../SentenceSample/SentenceSample.h ../StringBag/StringBag.h Gibberisher.h
# 	g++ -c -g main.cpp

# Gibberisher.o : Gibberisher.cpp ../SentenceSample/SentenceSample.h ../StringBag/StringBag.h Gibberisher.h
# 	g++ -c -g Gibberisher.cpp

CXX = g++
CXXFLAGS = -g

OBJECTS = ./StringBag/StringBag.o ./SentenceSample/SentenceSample.o ./Gibberisher/Gibberisher.o gibberisher_main.o

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): ./src/StringBag.h ./src/SentenceSample.h ./src/Gibberisher.h

clean :
	rm -f *.o main

