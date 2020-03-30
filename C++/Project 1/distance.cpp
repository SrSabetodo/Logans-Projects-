#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Pixel
{
    int r,g,b;
};

float get_distance(vector<Pixel> c1, vector<Pixel> c2);

int main()
{
    
    vector<Pixel> c1(1);
    vector<Pixel> c2(1);
    
    c1[0].r = 100;
    c1[0].g = 100;
    c1[0].b = 100;

    c2[0].r = 255;
    c2[0].g = 255;
    c2[0].b = 255;

    float number = get_distance(c1,c2);

    cout<<"Distance is: "<<number;

    return 0;
}

float get_distance(vector<Pixel> c1, vector<Pixel> c2)
{
    int c1r = c1[0].r;
    int c1g = c1[0].g;
    int c1b = c1[0].b;

    int c2r = c2[0].r;
    int c2g = c2[0].g;
    int c2b = c2[0].b;

    return sqrt(((c1r - c2r) * (c1r - c2r)) + ((c1g - c2g) * (c1g - c2g)) + ((c1b - c2b) * (c1b - c2b)));
}