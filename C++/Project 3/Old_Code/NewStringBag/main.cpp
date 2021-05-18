#include "StringBag.h"
#include <cctype>
#include <time.h>
#include <cstdlib>
#include <string>
#include <unordered_set>

int main()
{
    StringBag cb;

    srand (time(NULL));

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
        if(tester != cb.getRandomString())
        {
            std::cout<<"Test failed -- charBag should only randomly generate \"a\""<<std::endl;
        }
        else 
        {
            std::cout<<"yaaaaay! it generated the right string!!"<<std::endl;
        }
    }

    cb.remove("a");
    for(char c = 'a'; c <= 'z'; c++)
    {   
        std::string thiss = "";
        thiss += c;
        if(cb.getCount(thiss) != 0)
        {
            std::cout << "Test failed -- empty CharBag has something in it!" << std::endl;
        }
    }

    std::cout << cb.getSize() << std::endl; // 0 

    tester = ".";
    for(int i = 0; i < 100; i++)
    {
        if(tester != cb.getRandomString())
        {
            std::cout<<"Test failed -- charBag should only randomly generate \"a\""<<std::endl;
        }
        else
        {
            std::cout<<"yaaaaay! it generated the right string again!!"<<std::endl;
        }
        
    }

    cb.add("Hello my name is Logan.");

    std::cout << cb << std::endl;
    std::cout << cb.getSize() << std::endl;

    return 0;
}