#include "StringBag.h"

stringBag_t StringBag::getBag()
{
    return bagVec;
}

void StringBag::add(const std::string &addMe)
{
    bagVec.insert(std::upper_bound(bagVec.begin(), bagVec.end(), addMe), addMe);
}

void StringBag::remove(const std::string &removeMe)
{
    bagVec.erase(std::lower_bound(bagVec.begin(), bagVec.end(), removeMe));
}

int StringBag::getCount(const std::string countof)
{
    iterator_t it = std::lower_bound(bagVec.begin(), bagVec.end(), countof); // get first occurance of element in vector

    int count = 0;

    for (; *it == countof; it++) // since they will all be next to each other, we only need to look while it == countof
    {
        count++;
    }

    return count;
}

int StringBag::getSize()
{
    return bagVec.size();
}

std::ostream &operator<<(std::ostream &os, StringBag &bag)
{
    os << "StringBag{";

    int counter = 0;

    for(; counter != bag.getSize(); counter++)
    {
        if(counter == 0)
        {
            os << bag.getBag()[counter] << ":" << bag.getCount(bag.getBag()[counter]) << ", ";
        }
        else if(counter > 0 && bag.getBag()[counter-1] != bag.getBag()[counter])
        {
            os << bag.getBag()[counter] << ":" << bag.getCount(bag.getBag()[counter]) << ", ";
        }
        else
        {
            continue;
        }
    }

    os << "}"; 
    
    return os;
}