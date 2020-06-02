#include "StringBag.h"
#include <cctype>
#include <sstream>
#include <random>

std::string *getWords(std::string sentence, int &length)
{
    int numspaces = 0;

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
        {
            numspaces++;
        }
    }
    int numWords = numspaces + 1;

    std::istringstream ss(sentence);
    int it = 0;
    std::string *stringArray = new std::string[numWords];
    for (int i = 0; i < numWords; i++)
    {
        std::string word;
        ss >> word;
        std::string newstring = "";
        for (int i = 0; i < word.length(); i++)
        {
            if (isupper(word[i]))
            {
                word[i] = tolower(word[i]);
            }

            if (isspace(word[i]) || isalpha(word[i]))
            {
                newstring += word[i];
            }

            // if(i == word.length()-1)
            // {
            //     stringArray[numWords] = word[i];
            // }
        }

        stringArray[it] = newstring;
        it++;
    }

    length = numWords;

    return stringArray;
}

void StringBag::add(std::string addMe)
{
    int length;

    std::string* words = getWords(addMe, length);

    for(int i = 0; i < length + 1; i++) 
    {
        StringArray.push_back(words[i]);
    }

    delete [] words;
}

void StringBag::remove(std::string removeMe)
{
    for(int i = 0; i < StringArray.size(); i++)
    {
        if(StringArray[i] == removeMe)
        {
            std::string copy = StringArray.back();
            StringArray.back() = StringArray[i];
            StringArray[i] = copy;
            StringArray.pop_back();
            break;
        }
    }
}

int StringBag::getCount(std::string findCount)
{
    int count = 0;

    for(auto& x: StringArray)
    {
        if(x == findCount)
        {
            count++;
        }
    }

    return count;
}

int StringBag::getSize()
{
    return StringArray.size();
}

std::vector<std::string> StringBag::getVector()
{
    return StringArray;
}

std::ostream &operator<<(std::ostream& os, StringBag bag)
{
    std::string returner = "";
    for(auto& x: bag.getVector())
    {
        returner += x + ",";
    }

    std::cout << "StringBag{" << "\"" << returner << "\"" "}" << std::endl;

    return os;
}

std::string StringBag::getRandomString()
{
    if(StringArray.size() == 0)
    {
        return ".";
    }
    int randIndex = rand() % StringArray.size();
    
    return StringArray[randIndex];
}