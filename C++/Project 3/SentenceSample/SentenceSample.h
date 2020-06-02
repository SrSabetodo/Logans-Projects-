#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

class SentenceSample
{
private:
    std::string sentenceString;
    std::string nextWord;

public:
    static const char STOP = '.';
    SentenceSample(std::string sentenceString, std::string nextWord);
    SentenceSample() {}
    std::string getSentence();
    std::string getNextWord();
    static int getNumWords(std::string input);
    static std::string *returnWordsInString(std::string input, int length);
    friend std::ostream &operator<<(std::ostream &os, SentenceSample &sample);
    static std::vector<SentenceSample> toSamples(std::string inputString, int segmentSize)
    {
        std::string newstring = "";

        for (int i = 0; i < inputString.length(); i++)
        {
            if (isupper(inputString[i]))
            {
                inputString[i] = tolower(inputString[i]);
            }

            if (isspace(inputString[i]) || isalpha(inputString[i]))
            {
                newstring += inputString[i];
            }
        }
        newstring += SentenceSample::STOP;

        int numberWords = SentenceSample::getNumWords(newstring);
        std::vector<SentenceSample> wordArray(numberWords);
        std::string *stringArray = SentenceSample::returnWordsInString(newstring, numberWords);
        int start = 0, stop;

        for (int n = 0; n < numberWords; n++)
        {
            std::string sentence = "";
            if (n < segmentSize)
            {
                for (int i = 0; i < n; i++)
                {
                    if (n > 1)
                    {
                        sentence += stringArray[i] + " ";
                    }
                    else
                    {
                        sentence += stringArray[i];
                    }
                }
                wordArray[n] = SentenceSample(sentence, stringArray[n]);
            }
            else
            {
                stop = n;
                for (int i = start; i < stop; i++)
                {
                    if (i < stop - 1)
                    {
                        sentence += stringArray[i] + " ";
                    }
                    else
                    {
                        sentence += stringArray[i];
                    }
                }
                wordArray[n] = SentenceSample(sentence, stringArray[n]);
                start++;
                stop++;
            }
        }
        delete[] stringArray;
        return wordArray;
    }
};