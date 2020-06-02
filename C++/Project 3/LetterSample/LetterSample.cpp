#include "LetterSample.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

LetterSample::LetterSample(std::string segmentString, char nextLetter)
{
    this->segmentString = segmentString;
    this->nextLetter = nextLetter;
}

std::string LetterSample::getSegment() 
{
    return segmentString;
}

char LetterSample::getNextLetter()
{
    return nextLetter;
}

std::ostream& operator<< (std::ostream& os, LetterSample& sample)
{
    os << "\"" << sample.segmentString << "\"" << " -> " << sample.nextLetter;
    return os;
}

std::vector<LetterSample> LetterSample::toSamples(std::string input, int segmentSize)
{
    std::string newstring = "";

    for(int i = 0; i < input.length(); i++) 
    {
        char variable = input[i];
        if(isupper(variable))
        {
            variable = tolower(variable);
        }

        if(isspace(variable) || isalpha(variable))
        {
            newstring += variable;
        }
    }
    newstring += STOP;

    std::vector<LetterSample> letterArray(newstring.length());
    int stop, start = 0;

    for(int n = 0; n < newstring.length(); n++)
    {
        std::string adder = "";
        if(n < segmentSize)
        {
            for(int i = 0; i < n; i++)
            {
                adder += newstring[i];
            }
            letterArray[n] = LetterSample(adder, newstring[n]);
        }
        else 
        {
            stop = n;
            for(int i = start; i < stop; i++) 
            {
                adder += newstring[i];
            }
            letterArray[n] = LetterSample(adder, newstring[n]);
            start++;
            stop++;
        }
    }
    
    return letterArray;
}