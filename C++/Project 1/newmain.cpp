#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>

int ***read_ppm(int width, int height, int*** image);
int random_color();
int **first_guess(int k, int **means_list);
void get_widthAndheight(int &width, int &height);
using namespace std;

int main()
{
    srand(time(NULL)); // seeding time thingy..

    int k = 7; // num colors, k set to 7 for example 
    
    int width, height; // Declare width and height variables so can can pass by reference
    
    get_widthAndheight(width, height); // Get width and height returned by reference 
    
    cout<<"got to this"<<endl;

    int **means_list = new int *[k];
    for (int i = 0; i < k; i++)
    {
        means_list[i] = new int[3]; //create the dynamic 2D array means_list
    }

    cout<<"Got to here mate"<<endl;
    cout<<"Now got here matealihfskoudjghfkaudhfksjdh'vbg"<<endl;

    int ***image = new int **[width];

        for (int i = 0; i < width; i++)
        {
            image[i] = new int *[height];

            for (int j = 0; j < height; j++)
            {
                image[i][j] = new int[3];
            }
        }

   
    image = read_ppm(width, height, image); // get image data

    means_list = first_guess(k, means_list); // populate means list with random colors

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<<means_list[i][j]<<" ";
        }
    }

    /* ===== Deallocating image ===== */
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            delete[] image[i][j];
        }
        delete[] image[i];
    }
    delete[] image;

    /* ===== Deallocating means_list ===== */
    for (int i = 0; i < 9; ++i)
    {
        delete[] means_list[i];
    }
    delete[] means_list;

    return 0;
}

int ***read_ppm(int width, int height, int*** image)
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
                image[width1][height1][0] = image_dat[looper];     // first index equals looper, which is initially 0
                image[width1][height1][1] = image_dat[looper + 1]; // second index equals looper + 1 since it is one above the first index
                image[width1][height1][2] = image_dat[looper + 2]; // third index equals looper + 2 since it is two above the second index

                looper += 3; // add 3 to the looper since we added 3 elements to the array
            }
        }
    return image; // Return array so we can have it in main
    }
}

void get_widthAndheight(int &width, int &height)
{
    ifstream myFile; // declare ifstream object
    myFile.open("Peik_Hall_University_of_Minnesota_5-tiny.ppm"); //open file
    string reader;

    string type;
    string height1;
    string width1;

    if (myFile.is_open()) // check to see if file is open
    {
        int counter = 1;
        while (counter < 4) // read from file into string, reader
        {
            myFile >> reader;
            
            if(counter == 1)
            {
                type = reader;
            }
            if(counter == 2)
            {
                width1 = reader;
            }
            if(counter == 3)
            {
                height1 = reader;
            }

            counter++;
        }
        height = stoi(height1); // cast the string values for height and width to ints
        width = stoi(width1);

        // width = width1;
        // height = height1;
    }
}

int random_color()
{
    return rand() % 256;
}

int **first_guess(int k, int **means_list)
{

    for (int i = 0; i < k; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            means_list[i][k] = random_color();
        }
    }
    return means_list;
}
