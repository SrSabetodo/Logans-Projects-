#include "LetterSample.h"

class LetterSample_Array
{
public:
    LetterSample_Array(int size) 
    {
        point = new LetterSample[size];
    }

    LetterSample_Array(const LetterSample_Array &obj)
    {
        point = new LetterSample[size];
        *point = *obj.point;
    }

    LetterSample_Array(const LetterSample_Array &obj)
    {
        size = obj.size;
        *point = *obj.point;
    }

    ~LetterSample_Array()
    {
        delete [] point;
    }
private:
    LetterSample* point;
    int size;
};