#include "SentenceSample.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

SentenceSample::SentenceSample(std::string sentenceString, std::string nextWord)
{
    this->sentenceString = sentenceString;
    this->nextWord = nextWord;
}

std::string SentenceSample::getSentence()
{
    return sentenceString;
}

std::string SentenceSample::getNextWord()
{
    return nextWord;
}

std::ostream &operator<<(std::ostream &os, SentenceSample &sample)
{
    os << "\"" << sample.sentenceString << "\""
       << " -> " << sample.nextWord;
    return os;
}

int SentenceSample::getNumWords(std::string input)
{
    int numSpaces = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            numSpaces++;
        }
    }
    return (numSpaces + 1);
}

std::string *SentenceSample::returnWordsInString(std::string input, int length)
{
    std::istringstream ss(input);
    int iterator = 0;
    std::string *stringArray = new std::string[length];
    for (int i = 0; i < length; i++)
    {
        std::string word;
        ss >> word;
        stringArray[iterator] = word;
        iterator++;
    }
    return stringArray;
}