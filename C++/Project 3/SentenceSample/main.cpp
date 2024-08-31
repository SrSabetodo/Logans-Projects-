/**
 * @author Logan Kreun
 * @details Simple little file to test out SentenceSample
 */
#include "SentenceSample.h"

int main()
{

    std::cout << STOP << std::endl;

    SentenceSample ls("Hello my name is logan", "alpha");
    std::cout << ls << std::endl;

    std::vector<SentenceSample> vect;
    vect = SentenceSample::toSamples("Hello my name is logan", 3);
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << ", ";
    }
    vect.clear();

    std::cout << std::endl;

    vect = SentenceSample::toSamples("The reason that I feel this say.", 2);
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << ", ";
    }
    vect.clear();

    std::cout << std::endl;

    vect = SentenceSample::toSamples("Hello my name is logan and I like bread", 0);
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << ", ";
    }
    vect.clear();

    std::cout << std::endl;

    vect = SentenceSample::toSamples("@HeLlO mY! Name! is! Logian!", 4);
    for (int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << ", ";
    }
    vect.clear();


    puts("");

    std::vector<std::string> nvect = SentenceSample::returnWordsInString("test one two three");
    for (int i = 0; i < nvect.size(); i++)
    {
        std::cout << nvect[i] << ", ";
    }

    return 0;
}

// .
// "Hello my name is logan" -> alpha

// "" -> hello, "hello" -> my, "hello my " -> name, "hello my name" -> is, "my name is" -> logan, "name is logan" -> and, "is logan and" -> i, "logan and i" -> like, "and i like" -> bread.,
// "" -> the, "the" -> reason, "the reason" -> that, "reason that" -> i, "that i" -> feel, "i feel" -> this, "feel this" -> say.,
// "" -> hello, "" -> my, "" -> name, "" -> is, "" -> logan, "" -> and, "" -> i, "" -> like, "" -> bread.,
// "" -> hello, "hello" -> my, "hello my " -> name, "hello my name " -> is, "hello my name is" -> logian, "my name is logian" -> and, "name is logian and" -> i, "is logian and i" -> dont, "logian and i dont" -> know, "and i dont know" -> what, "i dont know what" -> to, "dont know what to" -> say.,