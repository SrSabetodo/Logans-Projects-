/**
 * @author Logan Kreun
 * @brief  LetterSample Class 
 * @details This class is used to break down sentences into words 
 */
#include <string>
#include <vector>

class LetterSample 
{
    private:
        std::string segmentString;
        char nextLetter;
    public:
        static const char STOP = '.';
        LetterSample(std::string segmentString, char nextLetter);
        LetterSample(){}
        std::string getSegment();
        char getNextLetter();
        friend std::ostream& operator<< (std::ostream& os, LetterSample& sample);
        static std::vector<LetterSample> toSamples(std::string input, int segmentSize);
};