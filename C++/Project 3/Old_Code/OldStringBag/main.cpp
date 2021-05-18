#include "StringBag.h"
#include <cctype>
#include <time.h>
#include <cstdlib>
#include <string>
#include <unordered_set>

int main()
{
    StringBag cb;

    for(char c = 'a'; c <= 'z'; c++)
    {   
        std::string thiss = "";
        thiss += c;
        if(cb.getCount(thiss) != 0)
        {
            std::cout << "Test failed -- empty CharBag has something in it!" << std::endl;
        }
    }
    cb.add("a");
    std::cout<<cb.getCount("a")<<std::endl; // 1
    std::cout<<cb.getSize()<<std::endl; // 1


    std::string tester = "a";
    for(int i = 0; i < 100; i++)
    {
        int x = tester.compare(cb.getRandomString());
        if(x != 0)
        {
            std::cout<<"Test failed -- charBag should only randomly generate \"a\""<<std::endl;
        }
        // else if(x == 0)
        // {
        //     std::cout<<"yaaaaay! it generated the right string!!"<<std::endl;
        // }
    }

    cb.remove("a");
    std::unordered_multiset<std::string> testingBag = cb.returnBag();
    std::unordered_multiset<std::string>::iterator it = testingBag.begin();
    for(; it!= testingBag.end(); it++)
    {
        if(cb.getCount(*it) != 0)
        {
            std::cout<<"Test failed -- empty StringBag has something in it!"<<std::endl;
        }
        else
        {
            std::cout<<"Yaaay! The StringBag was empty when it was supposed to be!"<<std::endl;
        }
    }

    std::string toAdd = "Hello my name is Logan";
    cb.add(toAdd);
    std::cout << cb << std::endl;

    
    return 0;
}