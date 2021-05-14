#include "StringBag.h"

int main()
{
    using std::cout;
    using std::endl;

    StringBag bag;

    cout << (bag.getBag().empty() ? "true\n" : "false\n");

    bag.add("hello mate!");

    cout << (bag.getBag().empty() ? "true\n" : "false\n");

    bag.add("bread and butter");
    bag.add("apples and oranges");
    bag.add("apples and oranges");
    bag.add("bread and butter");

    for(std::string i : bag.getBag())
    {
        cout << i << endl;
    }

    bag.remove("bread and butter");

    puts("");

    for(std::string i : bag.getBag())
    {
        cout << i << endl;
    }

    puts("");

    cout << "count of apples and oranges is : " << bag.getCount("apples and oranges") << endl;
    cout << "size is: " << bag.getSize() << endl;

    // iterator_t it = bag.getBag().begin();
    
    // for(iterator_t iter = bag.getBag().begin(); iter < bag.getBag().end(); iter++)
    // {
    //     std::cout << *iter << std::endl;
    // }

    cout << bag << endl;//
    return 0;
}