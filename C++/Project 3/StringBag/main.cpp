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


    puts("");
    
    // Test if random string is 50/50 distribution with this data set.
    StringBag bag2;

    bag2.add("apples and oranges");
    bag2.add("apples and oranges");
    bag2.add("bread and butter");
    bag2.add("honey and rye");

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    std::cout << bag2 << std::endl;

    for (int i = 0 ; i < 50000; i++)
    {
      std::string str = bag2.getRandomString();
      if ("apples and oranges" == str)
      {
        count1++;
      }
      else if ("bread and butter" == str)
      {
        count2++;
      }
      else if ("honey and rye" == str)
      {
        count3++;
      }
      else
      {
        std::cout << "Error!";
      }
    }

    std::cout << "Count1: " << count1/50000.0 << std::endl
              << "Count2: " << count2/50000.0 << std::endl
              << "Count3: " << count3/50000.0 << std::endl;

    return 0;
}