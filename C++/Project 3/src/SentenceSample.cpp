/**
 * @author Logan Kreun
 * @details Class to split sentences into samples of size sentence sample
 */

#include "SentenceSample.h"

/**
 * Default constructor for constructing SentenceSample objects
 * @param sentenceString string that makes up the string portion of the sample
 * @param nextWord the 'next word' after sentenceString
 */
SentenceSample::SentenceSample(std::string sentenceString, std::string nextWord)
{
  this->sentenceString = sentenceString;
  this->nextWord = nextWord;
}

/**
 * Getter for sentenceString
 * @return string sentenceString
 */
std::string SentenceSample::getSentence()
{
  return sentenceString;
}

/**
 * Getting for next word in sample
 * @return nextWord part of sentence sample
 */
std::string SentenceSample::getNextWord()
{
  return nextWord;
}

/**
 * Overload << operator to output sentence samples in a readable manner
 * @param os output stream
 * @param sample SentenceSample sample to send to output stream
 * @return output stream w/ newly created SentenceSample string
 */
std::ostream &operator<<(std::ostream &os, SentenceSample &sample)
{
  os << "\"" << sample.sentenceString << "\""
     << " -> \"" << sample.nextWord << "\"";
  return os;
}

/**
 * returnWordsInString accepts a string an number of words, and returns an
 * array of size length of the words in input
 * @param input string to 'split' into words
 * @param length number of words in string
 * @param stringVec array consisting of the words in input
 */
std::vector<std::string> SentenceSample::returnWordsInString(
  std::string input, bool addStopAtEnd)
{
  // create an istringsstream object with our input string
  std::istringstream ss(input);

  // create an array of size length
  std::vector<std::string> senSample;
  std::string word;
  while (ss >> word) // extract words from ss, which was constructed using input
  {
    senSample.push_back(word);  // add words to stringVec
  }

  // Usually added by default, but not wanted in Gibberisher class.
  if (addStopAtEnd)
  {
    senSample.push_back(STOP); // Add final period
  }
  return senSample;
}

/**
 * toSamples accepts a string and segment size, and splits the string into
 * segments according to segmentSize, and returns them in a vector
 * @param inputString string to split into samples
 * @param segmentSize size of segments to split inputString into
 * @return vector of SentenceSample objects, representing the samples the
 *         string has been split into.
 */
std::vector<SentenceSample> SentenceSample::toSamples(
    std::string inputString, int segmentSize)
{
  std::string newstring = ""; // init to empty

  // process string, get rid of uppercase and non alphabetic symbols.
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

  // get an array of all the words in inputString
  std::vector<std::string> stringVec =
      SentenceSample::returnWordsInString(newstring);

  // get num of words
  int numberWords = stringVec.size();

  // create vector wordArray of size numberWords
  std::vector<SentenceSample> wordArray(numberWords);

  int start = 0, stop;

  // n represents segment size, that will keep increasing
  for (int n = 0; n < numberWords; n++)
  {
    std::string sentence = ""; // start with an empty sentence

    // first few cases where n is less than segmentSize, so we just keep
    // adding more words to sentence
    if (n < segmentSize)
    {
      for (int i = 0; i < n; i++)
      {
        // 'default' case where we just add empty string as the next
        // word
        if (n > 1)
        {
          sentence += stringVec[i] + " ";
        }
        // Special first case when we just want to add the word and no
        // space after it
        else
        {
          sentence += stringVec[i];
        }
      }

      // clean up so there are no extra spaces after a sample
      if (isspace(sentence[sentence.length() - 1]))
      {
        sentence = sentence.substr(0, sentence.length() - 1);
      }

      // add sample to wordArray
      wordArray[n] = SentenceSample(sentence, stringVec[n]);
    }
    // all other cases when n > segment size
    else
    {
      stop = n;
      // by incrementing using start and stop, we can 'step' through the
      // inputString 1 word at a time
      for (int i = start; i < stop; i++)
      {
        if (i < (stop - 1))
        {
          sentence += stringVec[i] + " ";
        }
        else
        {
          sentence += stringVec[i];
        }
      }
      start++;
      stop++;

      // add new object to our array
      wordArray[n] = SentenceSample(sentence, stringVec[n]);
    }
  }
  return wordArray;
}