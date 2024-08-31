#include "../StringBag/StringBag.h"
#include "../SentenceSample/SentenceSample.h"
#include <map>

class Gibberisher
{
  private:
    std::map<std::string, StringBag> stringBagMap;
    int segmentLength;
    int numberSamplesProcessed;

  public:
    Gibberisher(int length);
    void train(SentenceSample sample);
    void train(std::vector<std::string> samplesVec);
    int getNumSamplesProcessed();
    std::string getLastKWords(std::vector<std::string> fragments);
    std::string generate();
    std::vector<std::string> getTrainingDataVector(
      std::vector<std::string> files);
};