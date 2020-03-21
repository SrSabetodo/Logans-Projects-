#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

struct Pixel
{
    int r, g, b;
};

void read_ppm(vector<vector<Pixel>> &image, int width, int height);
int random_color();
void first_guess(int k, vector<Pixel> &means_list);
void get_widthAndheight(int &width, int &height);
void average(vector<Pixel> &vect, int &red, int &blu, int &grn);
float get_distance(vector<Pixel> c1, vector<Pixel> c2);
void update_assignments(const vector<vector<Pixel>> &image, vector<vector<int>> &assignments, const int width, const int height, const vector<Pixel> &means_list);
void update_means(const vector<vector<Pixel>> &image, const vector<vector<int>> &assignments, const int width, const int height, vector<Pixel> &means_list, const int k);
void label(vector<vector<Pixel>> &image, vector<vector<int>> &assignments, const int width, const int height, vector<Pixel> &means_list); 
void save_ppm(string filename, vector<vector<Pixel>> &image, const int width, const int height);

// TODO
// Write and implement means and assignments list functions

int main()
{

    srand(time(NULL)); // seeding time thingy..

    int k = 7;                     // num colors, k set to 7 for example
    int width, height;             // Declare width and height variables so can can pass by reference
    cout<<"Got here 1!"<<endl;
    get_widthAndheight(width, height); // Get width and height returned by reference
     cout<<"Got here 2!"<<endl;
    vector<vector<Pixel>> image(width, vector<Pixel>(height)); // create a width X height vector of RGB objects
     cout<<"Got here 3!"<<endl;
    read_ppm(image, width, height); // get image data
     cout<<"Got here 4!"<<endl;
    vector<Pixel> means_list(k); // create a k long vector of RGB objects
     cout<<"Got here 5!"<<endl;
    first_guess(k, means_list); // Populate list with random colors first
     cout<<"Got here 6!"<<endl;
    vector<vector<int>> assignments(width, vector<int>(height)); // create assignment list
     cout<<"Got here 7!"<<endl;
    vector<vector<int>> old_assignments(width, vector<int>(height));
    do
    {
        old_assignments = assignments;
         cout<<"Got here 9!"<<endl;
        update_means(image, assignments, width, height, means_list, k);
        cout<<"Got here 9.1"<<endl;
        update_assignments(image, assignments, width, height, means_list);
        cout<<"Got here 9.2!"<<endl;
    } while(old_assignments != assignments);

     cout<<"Got here 10!"<<endl;
    label(image, assignments, width, height, means_list);
     cout<<"Got here 11!"<<endl;
    string filename = "please_work.ppm";
     cout<<"Got here 12!"<<endl;
    save_ppm(filename, image, width, height);
     cout<<"Got here 13"<<endl;
    return 0; // return 0
}

void read_ppm(vector<vector<Pixel>> &image, int width, int height)
{
    ifstream myFile; // declare ifstream object

    myFile.open("Peik_Hall_University_of_Minnesota_5-tiny.ppm"); //open file

    string reader;       // declare function to read strings from file into
    vector<string> list; // declare vector to hold file

    bool typeFlag = false;             // bool to ensure ppm file is the correct format
    bool colorReprensentation = false; // bool to make sure colors are ints from 0 to 255

    if (myFile.is_open()) // check to see if file is open
    {
        while (myFile >> reader) // read from file into string, reader
        {
            list.push_back(reader); // add that string to the back of the vector
        }
    }

    else // if file cannot be opened for some reason
    {
        cout << "Error opening file!" << endl;
    }

    int size = height * width; // the size of the image_dat array is equal to height times width
    size *= 3;                 // times three since every pixel has 3 elements

    int image_dat[size]; // make a array of size... size

    for (int i = 0; i < size; i++) // loop through image_dat array
    {
        string temp = list[i + 4]; // set the temp variable equal to a specific index + 4, since first 4 indexes contain image info
        image_dat[i] = stoi(temp); // cast temp to int and add to array
    }

    if (list[0] != "P3") // make sure the ppm file is a P3 ppm
    {
        cout << "Error! This file is not of the right ppm format!" << endl;
        typeFlag = true; // if it isn't a P3 ppm, set this flag to true
    }

    if (list[3] != "255") // if the colors aren't from 0 to 255
    {
        cout << "ppm image uses a different color representation (not 255)" << endl;
        colorReprensentation = true; // set this flag to true
    }

    if (typeFlag == false && colorReprensentation == false) // if the ppm file passes both tests, continue onwards!
    {

        int looper = 0; // intialize looper to zero so we can loop with it

        for (int height1 = 0; height1 < height; height1++) // loop through height first
        {
            for (int width1 = 0; width1 < width; width1++) // loop through width first
            {
                image[width1][height1].r = image_dat[looper];     // first index equals looper, which is initially 0
                image[width1][height1].g = image_dat[looper + 1]; // second index equals looper + 1 since it is one above the first index
                image[width1][height1].b = image_dat[looper + 2]; // third index equals looper + 2 since it is two above the second index
                looper += 3;                                      // add 3 to the looper since we added 3 elements to the array
            }
        }
    }
}

void get_widthAndheight(int &width, int &height)
{
    ifstream myFile;                                             // declare ifstream object
    myFile.open("Peik_Hall_University_of_Minnesota_5-tiny.ppm"); //open file
    string reader;                                               // declare string to read into

    string type;    // string to check variable type
    string height1; // string for height
    string width1;  // string for width

    if (myFile.is_open()) // check to see if file is open
    {
        int counter = 1;
        while (counter < 4) // read from file into string, reader
        {
            myFile >> reader;

            if (counter == 1)
            {
                type = reader;
            }
            if (counter == 2)
            {
                width1 = reader;
            }
            if (counter == 3)
            {
                height1 = reader;
            }
            counter++;
        }
        height = stoi(height1); // cast the string values for height and width to ints
        width = stoi(width1);
    }
}

int random_color()
{
    return rand() % 256;
}

void first_guess(int k, vector<Pixel> &means_list)
{
    for (int i = 0; i < k; i++)
    {
        means_list[i].r = random_color();
        means_list[i].g = random_color();
        means_list[i].b = random_color();
    }
}

void average(vector<Pixel> &vect, int &red, int &blu, int &grn)
{
    // be sure to return random color if length of assignment list is zero
    red = 0;
    blu = 0;
    grn = 0;

    for (int i = 0; i < vect.size(); i++)
    {
        red += vect[i].r;
        blu += vect[i].b;
        grn += vect[i].g;
    }

    int num_colors = vect.size();

    red = red / num_colors;
    blu = blu / num_colors;
    grn = grn / num_colors;

    cout<<"red: "<<red<<endl;
    cout<<"blu: "<<blu<<endl;
    cout<<"grn: "<<grn<<endl;
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

void update_assignments(const vector<vector<Pixel>> &image, vector<vector<int>> &assignments, const int width, const int height, const vector<Pixel> &means_list)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float distances[means_list.size()];
            vector<Pixel> c1(1);
            c1[0].r = image[j][i].r;
            c1[0].g = image[j][i].g;
            c1[0].b = image[j][i].b;

            for (int k = 0; k < means_list.size(); k++)
            {
                vector<Pixel> c2(1);
                c2[0].r = means_list[k].r;
                c2[0].g = means_list[k].g;
                c2[0].b = means_list[k].b;

                distances[k] = get_distance(c1, c2);
            }

            int smallest = 0;

            for (int n = 0; n < means_list.size(); n++)
            {
                if (distances[n] < distances[smallest])
                {
                    smallest = n;
                }
            }

            assignments[j][i] = smallest;
        }
    }
}

void update_means(const vector<vector<Pixel>> &image, const vector<vector<int>> &assignments, const int width, const int height, vector<Pixel> &means_list, const int k)
{
    for(int i = 0; i < k ; i++)
    {
        vector<Pixel> average_list;
        cout<<"Got here 10.1"<<endl;
        for (int n = 0; n < height; n++)
        {
            for (int j = 0; j < width; j++)
            {
                if(assignments[j][n] == i )
                {
                    cout<<"Got here 10.2"<<endl;
                    vector<Pixel> appender(1);
                    appender[0].r = image[j][n].r;
                    appender[0].g = image[j][n].g;
                    appender[0].b = image[j][n].b;
                    cout<<"Got here 10.3"<<endl;
                    average_list.push_back(appender[0]);
                }
            }
        }
        cout<<"Got here 10.4"<<endl;
        int red = 0, blu = 0, grn = 0;
        cout<<"Got here 10.5"<<endl;
        average(average_list, red, blu, grn);
        cout<<"Got here 10.55"<<endl;
        means_list[i].r = red;
        means_list[i].g = grn;
        means_list[i].b = blu;
        cout<<"Got here 10.6"<<endl;
    }

}

void label(vector<vector<Pixel>> &image, vector<vector<int>> &assignments, const int width, const int height, vector<Pixel> &means_list)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int index = assignments[j][i];
            image[j][i] = means_list[index];
        }
    }
}

void save_ppm(string filename, vector<vector<Pixel>> &image, const int width, const int height)
{
    ofstream outFile;
    outFile.open(filename);

    outFile << "P3\n";
    outFile << width<<" "<<height<<endl;
    outFile << "255\n"; 

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            outFile << image[j][i].r << " " <<  image[j][i].g << " "<<  image[j][i].b << " ";
        }
    }

    outFile.close();
}