#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int*** read_ppm(int& width, int& height);

using namespace std;

int main()
{
    int width, height; // Declare width and height variables so can can pass by reference

    int*** image = read_ppm(width, height);

    cout<<"Width is: "<<width<<endl<<"Height is: "<<height<<endl;

    cout<<image[0][0][0]<<" "<<image[0][0][1]<<" "<<image[0][0][2];    

    return 0;
}

int*** read_ppm(int& width, int& height)
{
    ifstream myFile; // declare ifstream object

    myFile.open("Peik_Hall_University_of_Minnesota_5-tiny.ppm"); //open file

    string reader; // declare function to read strings from file into
    vector<string> list; // declare vector to hold file

    bool typeFlag = false; // bool to ensure ppm file is the correct format
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
        /* ====== Pass width and height as reference so they need not be returned =====*/
        height = stoi(list[2]); // cast the string values for height and width to ints
        width = stoi(list[1]);

        int size = height * width; // the size of the image_dat array is equal to height times width
        size *= 3; // times three since every pixel has 3 elements

        int image_dat[size]; // make a array of size... size

        for (int i = 0; i < size; i++) // loop through image_dat array
        {
            string temp = list[i + 4]; // set the temp variable equal to a specific index + 4, since first 4 indexes contain image info
            image_dat[i] = stoi(temp); // cast temp to int and add to array 
        }
        
        /*===== Create this absolutely discusting dynamic 3D array... =====*/
        int*** image = new int**[width];
        
        for(int i = 0;i<width;i++)
        {
            image[i] = new int*[height];

            for (int j = 0; j < height; j++)
            {
                image[i][j] = new int[3];
            }
        }

        int looper = 0; // intialize looper to zero so we can loop with it 

        for (int height1 = 0; height1 < height; height1++) // loop through height first
        {
            for (int width1 = 0; width1 < width; width1++) // loop through width first
            {
                image[width1][height1][0] = image_dat[looper]; // first index equals looper, which is initially 0
                image[width1][height1][1] = image_dat[looper + 1]; // second index equals looper + 1 since it is one above the first index
                image[width1][height1][2] = image_dat[looper + 2]; // third index equals looper + 2 since it is two above the second index

                looper += 3; // add 3 to the looper since we added 3 elements to the array 
            }
        }
        return image; // Return array so we can have it in main
    }
}

