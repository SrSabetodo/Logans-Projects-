#include <iostream>
#include <vector>

using namespace std;

struct Pixel
{
    int r,g,b;
};

void tester(vector<Pixel> &pixels);

int main()
{
    vector<Pixel> pixels (4);

    for(int i =0;i<4;i++)
    {
        pixels[i].r = 255;
        pixels[i].g = 0;
        pixels[i].b = 0;
        
    }

    tester(pixels);

    return 0; 
}

void tester(vector<Pixel> &pixels)
{
    cout<<pixels[1].r<<" "<<pixels[1].g<<" "<<pixels[1].b;
}