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
    static std::vector<SentenceSample> toSamples(std::string inputString, int segmentSize);
};