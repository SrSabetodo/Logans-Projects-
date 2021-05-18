#include <string>
#include <iostream>
#include <vector>

class StringBag
{
    private:
        std::vector<std::string> StringArray;
    
    public:
        StringBag() 
        {
            std::vector<std::string*> StringArray = std::vector<std::string*>(1);
        }

        void add(std::string addMe);
        void remove(std::string removeMe);
        int getCount(std::string findCount);
        int getSize();
        std::vector<std::string> getVector();
        friend std::ostream &operator<<(std::ostream& os, StringBag bag);
        std::string getRandomString();
};