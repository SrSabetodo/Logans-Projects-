#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

class SentenceSample;

const std::string STOP = ".";

class SentenceSample
{
private:
  std::string sentenceString;
  std::string nextWord;

public:
  SentenceSample(std::string sentenceString, std::string nextWord);
  SentenceSample() {}
  std::string getSentence();
  std::string getNextWord();
  static std::vector<std::string> returnWordsInString(
    std::string input, bool addStopAtEnd = true);
  friend std::ostream &operator<<(std::ostream &os, SentenceSample &sample);
  static std::vector<SentenceSample>
    toSamples(std::string inputString, int segmentSize);
};