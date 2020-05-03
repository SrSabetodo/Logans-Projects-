#include <iostream>

void lowest_common_multiple(long int x, long int y);

int main()
{
    unsigned long int x,y;

    std::cout<<"Enter two numbers to calculate the LCM of: ";
    std::cin>>x;
    std::cout<<"Enter the second number: ";
    std::cin>>y;

    lowest_common_multiple(x,y);

    return 0;
}

void lowest_common_multiple(long int x, long int y)
{
    bool control = false;
    unsigned long int number;

    while(!control)
    {
        number++;
        if( number % x == 0 && number % y == 0)
        {
            std::cout<<"The lowest common multiple of "<<x<<" and "<<y<<" is "<<number<<std::endl;
            control = true;
        }
        
    }
}