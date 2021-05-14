#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> stringBag_t;
typedef stringBag_t::iterator iterator_t;
class StringBag
{
private:
    stringBag_t bagVec;

public:
    StringBag()
    {
        stringBag_t bagVec(0);
    }
    stringBag_t getBag();
    void add(const std::string &addMe);
    void remove(const std::string &removeMe);
    int getCount(const std::string countof);
    int getSize();
    friend std::ostream &operator<<(std::ostream &os, StringBag &bag);
    std::string getRandomString();
};