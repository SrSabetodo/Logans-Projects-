#include "SentenceSample.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main()
{

std::cout << SentenceSample::STOP<<std::endl;

SentenceSample ls("Hello my name is logan","alpha");
std::cout<<ls<<std::endl;

std::vector<SentenceSample> vect;
vect = SentenceSample::toSamples("Hello my name is logan and I like bread.",3);
for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<", ";
    }
vect.clear();

std::cout << std::endl;

vect = SentenceSample::toSamples("The reason that I feel this say.",2);
for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<", ";
    }
vect.clear();

std::cout << std::endl;

vect = SentenceSample::toSamples("Hello my name is logan and I like bread",0);
for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<", ";
    }
vect.clear();

std::cout << std::endl;


vect = SentenceSample::toSamples("@HeLlO mY! Name! is! Logian! and I don't know what to say", 4);
for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<", ";
    }
vect.clear();
return 0;
}