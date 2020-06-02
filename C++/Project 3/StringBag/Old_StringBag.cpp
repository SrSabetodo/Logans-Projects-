// #include "StringBag.h"
// #include <cctype>
// #include <time.h>
// #include <cstdlib>

// StringBag::StringBag() {}

// void StringBag::add(std::string addMe)
// {
//     using namespace std;

//     int numberWords = StringBag::getNumWords(addMe);
//     std::string *stringArray = StringBag::returnWordsInString(addMe, numberWords);
        
//     bag.insert(addMe);
    
//     delete [] stringArray;
// }

// void StringBag::remove(std::string removeMe)
// {
//     bag.erase(removeMe);
// }

// int StringBag::getCount(std::string findCount)
// {
//     std::string newstring = "";

//     for (int i = 0; i < findCount.length(); i++)
//     {
//         if (isupper(findCount[i]))
//         {
//             findCount[i] = tolower(findCount[i]);
//         }

//         if (isspace(findCount[i]) || isalpha(findCount[i]))
//         {
//             newstring += findCount[i];
//         }
//     }

//     return bag.count(newstring);
// }

// int StringBag::getSize()
// {
//     return bag.size();
// }

// std::string StringBag::getRandomString()
// {
//     if (bag.empty())
//     {
//         return ".";
//     }

//     int count = rand() % bag.size();

//     std::unordered_multiset<std::string>::iterator it = bag.begin();

//     for (; it != bag.end(); it++)
//     {
//         count -= bag.count(*it);
//         if (count < 0)
//         {
//             return *it;
//         }
//     }
//     return ".";
// }

// std::unordered_multiset<std::string>  StringBag::returnBag()
// {
//     return bag;
// }

// std::ostream &operator<<(std::ostream &os, StringBag bag)
// {
//     std::string returner = "";
    
//     std::unordered_multiset<std::string>::iterator it = bag.returnBag().begin();

//     for (; it != bag.returnBag().end(); it++)
//     {
//         returner += *it + ":";
//         int count = bag.returnBag().count(*it);
//         returner += count;
//     }

//     returner = "StringBag{" + returner + "}";

//     os << returner;

//     return os;
// }