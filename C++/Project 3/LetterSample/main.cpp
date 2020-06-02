#include "LetterSample.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout<<LetterSample::STOP<<std::endl;

    LetterSample ls("alpha",'b');
    std::cout<<ls<<std::endl;

    std::cout<<ls.getNextLetter()<<std::endl;
    std::cout<<ls.getSegment()<<std::endl;

    std::vector<LetterSample>vect;
    vect = LetterSample::toSamples("apple",2);
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<" ";
    }
    vect.clear();

    std::cout<<std::endl;

    vect = LetterSample::toSamples("happened", 4);
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<" ";
    }
    vect.clear();

    std::cout<<std::endl;

    vect = LetterSample::toSamples("maniac", 1);
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<" ";
    }
    vect.clear();

    std::cout<<std::endl;

    vect = LetterSample::toSamples("don't", 2);
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<" ";
    }
    vect.clear();

    std::cout<<std::endl;

    vect = LetterSample::toSamples("LaTeX", 3);
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<" ";
    }
    vect.clear();

    std::cout<<std::endl;
    
    vect = LetterSample::toSamples("lodge",0);
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] <<" ";
    }
    vect.clear();

    return 0;
}