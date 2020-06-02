#include <iostream>
#include <sstream>
#include <unordered_set>

class StringBag
{
public:
    StringBag();
    void add(std::string addMe);
    void remove(std::string removeMe);
    int getCount(std::string findCount);
    int getSize();
    std::string getRandomString();
    friend std::ostream &operator<<(std::ostream &os, StringBag bag);
    std::unordered_multiset<std::string> returnBag();
    static std::string *returnWordsInString(std::string input, int &length)
    {
        int numspaces = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ' ')
            {
                numspaces++;
            }
        }
        int numWords = numspaces + 1;

        std::istringstream ss(input);
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
            }
            
            stringArray[it] = newstring;
            it++;
        }

        length = numWords;

        return stringArray;
    }

private:
    std::unordered_multiset<std::string> bag;
};