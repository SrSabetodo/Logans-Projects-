#include "StringBag.h"
#include <sstream>



void StringBag::add(std::string addMe)
{
    int length = 0;

    std::string* stringArray = StringBag::getWordsInString(addMe, length);

    int needToAdd = length;

    for(int i = 0; i < size; i++)
    {
        for(int n = 0; n < length; n++)
        {
            if(StringBagArray[i].data == stringArray[n])
            {
                StringBagArray[i].count++;
                needToAdd--;
                stringArray[n] = "@@@";
            }
        }
    }

    if(needToAdd > size)
    {
        Element copyArray[2 * size];
        for(int i = 0; i < size; i++)
        {
            copyArray[i] = StringBagArray[i];
        }

        int ite = size;
        for(int i = 0; i < length; i++)
        {
            if(stringArray[i] != "@@@")
            {
                copyArray[ite].data = stringArray[i];
                ite++;
            }
        }
    }

}