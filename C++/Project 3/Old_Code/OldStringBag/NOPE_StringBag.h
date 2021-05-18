#include <string>
#include <array>
#include <sstream>

struct Element
{
    std::string data;
    int count = 0;
};

class StringBag
{
private:
    Element StringBagArray[2];
    int size;

public:
    StringBag() {size = 0;}
    void add(std::string addMe);
    static std::string *StringBag::getWordsInString(std::string inputString, int &length)
    {
        int numspaces = 0;
        for (int i = 0; i < inputString.length(); i++)
        {
            if (inputString[i] == ' ')
            {
                numspaces++;
            }
        }
        int numWords = numspaces + 1;

        std::istringstream ss(inputString);
        int it = 0;
        std::string *stringArray = new std::string[numWords];
        for (int i = 0; i < numWords; i++)
        {
            std::string word;
            ss >> word;
            stringArray[it] = word;
            it++;
        }

        length = numWords;

        return stringArray;
    }
    void remove(std::string removeMe);
    int getCount();
    int getSize();
    friend std::ostream &operator<<(std::ostream &os, StringBag bag);
    std::string getRandomString();
};