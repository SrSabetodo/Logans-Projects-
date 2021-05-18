// #include <iostream>
// #include <unordered_set>
// #include <sstream>

// class StringBag
// {
// public:
//     StringBag();
//     void add(std::string addMe);
//     void remove(std::string removeMe);
//     int getCount(std::string findCount);
//     int getSize();
//     std::string getRandomString();
//     friend std::ostream &operator<<(std::ostream &os, StringBag bag);
//     std::unordered_multiset<std::string> returnBag();
//     static int getNumWords(std::string input)
//     {
//         int numSpaces = 0;
//         for (int i = 0; i < input.length(); i++)
//         {
//             if (input[i] == ' ')
//             {
//                 numSpaces++;
//             }
//         }
//         return (numSpaces + 1);
//     }
//     static std::string *returnWordsInString(std::string input, int length)
//     {
//         std::istringstream ss(input);
//         int iterator = 0;
//         std::string *stringArray = new std::string[length];
//         for (int i = 0; i < length; i++)
//         {
//             std::string word;
//             ss >> word;
//             stringArray[iterator] = word;
//             iterator++;
//         }
//         return stringArray;
//     }

// private:
//     std::unordered_multiset<std::string> bag;
// };