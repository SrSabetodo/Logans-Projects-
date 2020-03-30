#include <iostream>
#include <array>

using namespace std;


void tester( array<array<array<int, 5>, 5>, 5> &apples);

int main()
{
    array<array<array<int, 5>, 5>, 5> apples;
    int counter = 0;

    tester(apples);
    
    cout<<endl;
    cout<<apples[0][0][0];
    return 0;
}

void tester(array<array<array<int, 5>, 5>, 5> &apples)
{
    apples[0][0][0] = 1234;
}