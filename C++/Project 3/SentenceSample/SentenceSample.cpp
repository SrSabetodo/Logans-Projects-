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
       << " -> " << sample.nextWord;
    return os;
}

/**
 * Finds the number of words in a sample, which is equal to the number of spaces + 1 
 * @param input string to find number of words 
 * @return number of words in string 
 */ 
int SentenceSample::getNumWords(std::string input)
{
    int numSpaces = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            numSpaces++;
        }
    }
    return (numSpaces + 1);
}

/**
 * returnWordsInString accepts a string an number of words, and returns an array of size length of the words in input 
 * @param input string to 'split' into words 
 * @param length number of words in string 
 * @param stringArray array consisting of the words in input  
 */
std::string *SentenceSample::returnWordsInString(std::string input, int length)
{
    std::istringstream ss(input);                       // create an istringsstream object with our input string
    int iterator = 0;                                   // start at 0
    std::string *stringArray = new std::string[length]; // create an array of size length
    for (int i = 0; i < length; i++)
    {
        std::string word;
        ss >> word;                   // extract words from ss, which was constructed using input
        stringArray[iterator] = word; // add words to stringArray
        iterator++;
    }
    return stringArray;
}

/**
 * toSamples accepts a string and segment size, and splits the string into segments according to segmentSize, and returns them in a vector 
 * @param inputString string to split into samples 
 * @param segmentSize size of segments to split inputString into 
 * @return vector of SentenceSample objects, representing the samples the string has been split into 
 */
std::vector<SentenceSample> SentenceSample::toSamples(std::string inputString, int segmentSize)
{
    std::string newstring = ""; // init to empty

    for (int i = 0; i < inputString.length(); i++) // process string, get rid of uppercase and non alphabetic symbols
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

    newstring += SentenceSample::STOP; // add STOP character at the end

    int numberWords = SentenceSample::getNumWords(newstring);                               // get num of words
    std::vector<SentenceSample> wordArray(numberWords);                                     // create vector wordArray of size numberWords
    std::string *stringArray = SentenceSample::returnWordsInString(newstring, numberWords); // get an array of all the words in inputString
    int start = 0, stop;

    for (int n = 0; n < numberWords; n++) // n represents segment size, that will keep increasing
    {
        std::string sentence = ""; // start with an empty sentence
        if (n < segmentSize)       // first few cases where n is less than segmentSize, so we just keep adding more words to sentence
        {
            // puts("here");
            for (int i = 0; i < n; i++)
            {
                if (n > 1) // 'default' case where we just add empty string as the next word
                {
                    sentence += stringArray[i] + " ";
                }
                else // Special first case when we just want to add the word and no space after it
                {
                    sentence += stringArray[i];
                }
            }

            if (isspace(sentence[sentence.length() - 1])) // clean up so there are no extra spaces after a sample
            {
                sentence = sentence.substr(0, sentence.length() - 1);
            }

            wordArray[n] = SentenceSample(sentence, stringArray[n]); // add sample to wordArray
        }
        else // all other cases when n > segment size
        {
            stop = n;
            for (int i = start; i < stop; i++) // by incrementing using start and stop, we can 'step' through the inputString 1 word at a time
            {
                if (i < (stop - 1))
                {
                    sentence += stringArray[i] + " ";
                }
                else
                {
                    sentence += stringArray[i];
                }
            }
            wordArray[n] = SentenceSample(sentence, stringArray[n]); // add new object to our array
            start++;
            stop++;
        }
    }
    delete[] stringArray; // cleanup
    return wordArray;
}