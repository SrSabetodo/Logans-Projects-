#include <iostream>
#include <vector>

using namespace std;

struct Pixel
{
    int r,g,b;
};

void average(vector<Pixel> &vect, int& red, int& blu, int& grn);

int main()
{
    vector<Pixel> vect(2);
    vect[0].r = 255;
    vect[0].g = 255;
    vect[0].b = 255;

    vect[1].r = 0;
    vect[1].b = 0;
    vect[1].g = 0;

    int red = 0, grn = 0, blu = 0;

    average(vect, red, blu, grn);

    cout<<"Average color is: "<<red<<" "<<blu<<" "<<grn;

    return 0;
}

void average(vector<Pixel> &vect, int& red, int& blu, int& grn)
{
    // be sure to return random color if length of assignment list is zero
    red = 0;
    blu = 0;
    grn = 0;

    for(int i = 0; i < vect.size() ; i++)
    {
        red += vect[i].r;
        blu += vect[i].b;
        grn += vect[i].g;
    }

    int num_colors = vect.size();

    red = red/num_colors;
    blu = blu/num_colors;
    grn = grn/num_colors;
}