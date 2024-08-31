#include "Gibberisher.h"
#include <fstream>

// TODO:
// looking into returnWordsInString -- may not be working right.

Gibberisher::Gibberisher(int length):
  segmentLength(length), numberSamplesProcessed(0) {}

void Gibberisher::train(SentenceSample sample)
{
  StringBag bag;

  if(stringBagMap.find(sample.getSentence()) == stringBagMap.end()) // not found
  {
    bag.add(sample.getNextWord());
    stringBagMap[sample.getSentence()] = bag;
  }
  else // found
  {
    stringBagMap[sample.getSentence()].add(sample.getNextWord());
  }

  numberSamplesProcessed++;
}

void Gibberisher::train(std::vector<std::string> stringVec)
{
  for (auto &sentence : stringVec)
  {
    std::vector<SentenceSample> sampleVec =
      SentenceSample::toSamples(sentence, segmentLength);

    for (auto& sample : sampleVec)
    {
      train(sample);
    }
  }
}

std::string Gibberisher::getLastKWords(std::vector<std::string> fragments)
{
  std::string sample = "";

  // Start at frag.size() - segment length, for example:
  // fragements.size() = 5, segmentLength = 3 ,=> 2, 3, 4
  for (int i=fragments.size() - segmentLength ; i < fragments.size() ; i++)
  {
    if (i + 1 == fragments.size())
    {
      sample += fragments[i];
    }
    else
    {
      sample += fragments[i] + " ";
    }
  }

  // std::cout << "Sample: " << sample << std::endl;
  return sample;
}

std::string Gibberisher::generate()
{
  std::string sentence = "";
  std::string prevWord = "";

  while(true)
  {
    std::string sample = "";

    // turn current sentence to vector of words to check amount of words
    std::vector<std::string> sentenceFragment =
      SentenceSample::returnWordsInString(sentence, false);

    if (sentenceFragment.size() <= segmentLength)
    {
        if (*sentence.end() == ' ')
        {
          std::string tempSentence = sentence;
          tempSentence.pop_back();
          sample = tempSentence;
        }
    }
    else
    {
      sample = getLastKWords(sentenceFragment);
    }

    std::string nextWord = stringBagMap[sample].getRandomString();

    // Attempt to not genereate dupes like "the the"
    while(prevWord == nextWord)
    {
      nextWord = stringBagMap[sample].getRandomString();
    }

    prevWord = nextWord;
    // std::cout << stringBagMap[sample] << std::endl;

    // std::cout << "nextWord: \"" + nextWord + "\"\n";
    // std::cout << "sentence: \"" + sentence + "\"\n";
    // std::cout << "sample: \"" + sample + "\"\n";

    // puts("");
    // puts("");
    // puts("");
    if ("." == nextWord)
    {
      sentence.back() = '.';
      break;
    }
    else
    {
      sentence += nextWord + " ";
    }
  }

  return sentence;
}

std::vector<std::string> Gibberisher::getTrainingDataVector(
  std::vector<std::string> files)
{
	std::ifstream myFile;
  std::string sentence = "";
  std::string word = "";
  std::vector<std::string> sentenceVec;

  for (auto &fileName : files)
  {
    myFile.open(fileName);

    if(myFile.is_open()) //check if document is open
    {
      while(myFile >> word) //while numbers are still on document
      {
        if ('?' == word.back() ||
            '!' == word.back() ||
            '.' == word.back())
        {
          sentence += " " + word;
          sentenceVec.push_back(sentence);
          sentence = "";
        }
        else
        {
          sentence += " " + word;
        }
      }
      myFile.close(); //close document
    }
    else
    {
      std::cout<<"Error opening file"<<std::endl;
    } //in case file doesn't open
  }

  return sentenceVec;
}

int Gibberisher::getNumSamplesProcessed()
{
  return numberSamplesProcessed;
}