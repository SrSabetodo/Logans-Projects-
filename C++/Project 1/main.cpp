#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>

void read_ppm(int width, int height, int ***image);
int random_color();
int **first_guess(int k, int **means_list);
void get_widthAndheight(int &width, int &height);
float get_distance(int c1[3], int c2[3]);
void update_assignments(int ***image, int ***assignments_list, const int width, const int height, int **means_list, const int k);
void update_means(int ***image, int ***assignments_list, const int width, const int height, int **means_list, const int k, const int MAX_SIZE);
void label(int ***image, int ***assignments_list, int **means_list, const int width, const int height);
void save_ppm(const std::string &filename, int ***image, const int width, const int height);

int main()
{
    srand(time(NULL)); // seeding time thingy..

    int k = 3; // num colors, k set to 7 for example

    int width, height; // Declare width and height variables so can can pass by reference

    get_widthAndheight(width, height); // Get width and height returned by reference

    const int MAX_SIZE = (width * height) * 3;

    /* ===== Allocating Dynamic Arrays ======*/
        int **means_list = new int *[k];
        for (int i = 0; i < k; i++)
        {
            means_list[i] = new int[3]; //create the dynamic 2D array means_list
        }

        int ***image = new int **[width];

        for (int i = 0; i < width; i++)
        {
            image[i] = new int *[height];

            for (int j = 0; j < height; j++)
            {
                image[i][j] = new int[3];
            }
        }

        int ***assignment_list = new int **[width];

        for (int i = 0; i < width; i++)
        {
            assignment_list[i] = new int *[height];

            for (int j = 0; j < height; j++)
            {
                assignment_list[i][j] = new int[1];
            }
        }

    
    
    read_ppm(width, height, image); // get image data

    means_list = first_guess(k, means_list); // populate means list with random colors
    
    update_assignments(image, assignment_list, width, height, means_list, k);

    bool bothListsEqual;

    int old_assignments[width][height][1];

    do
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                old_assignments[j][i][0] = assignment_list[j][i][0];
                std::cout<<assignment_list[j][i][0]<<" ";
            }
        }

        bothListsEqual = true;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (!old_assignments[j][i][0] == assignment_list[j][i][0])
                {
                    bothListsEqual = false;
                }
            }
        }

        for(int i = 0; i < k; i++)
        {
            std::cout<<"Means list is as follows:"<<std::endl;
            std::cout<<means_list[i][0]<<std::endl;
            std::cout<<means_list[i][1]<<std::endl;
            std::cout<<means_list[i][2]<<std::endl<<std::endl;

        }
        update_means(image, assignment_list, width, height, means_list, k, MAX_SIZE);
        update_assignments(image, assignment_list, width, height, means_list, k);

    } while (!bothListsEqual);

    label(image, assignment_list, means_list, width, height);

    std::string filename = "NEW_please_work.ppm";

    save_ppm(filename, image, width, height);
    /* ===== Deallocating Dynamic Arrays =====*/
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
        image = NULL;
        /* ===== Deallocating means_list ===== */
        for (int i = 0; i < k; ++i)
        {
            delete[] means_list[i];
        }
        delete[] means_list;
        means_list = NULL;

        /*===== Deallocating assignments_list =====*/
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                delete[] assignment_list[i][j];
            }
            delete[] assignment_list[i];
        }
        delete[] assignment_list;
        assignment_list = NULL;

    return 0;
}

void read_ppm(const int width, const int height, int ***image)
{
    std::ifstream myFile; // declare ifstream object

    myFile.open("Southeast_Steam_Plant-University_of_Minnesota-large.ppm"); //open file

    std::string reader;  // declare function to read strings from file into
    std::vector<std::string> list; // declare vector to hold file

    bool typeFlag = false;             // bool to ensure ppm file is the correct format
    bool colorReprensentation = false; // bool to make sure colors are ints from 0 to 255
    int counter = 0;

    if (myFile.is_open()) // check to see if file is open
    {
        while (myFile >> reader) // read from file into string, reader
        {
            list.push_back(reader); // add that string to the back of the vector
        }
    }

    else // if file cannot be opened for some reason
    {
        std::cout << "Error opening file!" << std::endl;
    }

    int size = height * width; // the size of the image_dat array is equal to height times width
    size *= 3;                 // times three since every pixel has 3 elements

    int image_dat[size]; // make a array of size... size

    for (int i = 0; i < size; i++) // loop through image_dat array
    {
        std::string temp = list[i + 4]; // set the temp variable equal to a specific index + 4, since first 4 indexes contain image info
        image_dat[i] = stoi(temp); // cast temp to int and add to array
    }

    if (list[0] != "P3") // make sure the ppm file is a P3 ppm
    {
        std::cout << "Error! This file is not of the right ppm format!" << std::endl;
        typeFlag = true; // if it isn't a P3 ppm, set this flag to true
    }

    if (list[3] != "255") // if the colors aren't from 0 to 255
    {
        std::cout << "ppm image uses a different color representation (not 255)" << std::endl;
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
    }
}

void get_widthAndheight(int &width, int &height)
{
    std::ifstream myFile;                                        // declare ifstream object
    myFile.open("Peik_Hall_University_of_Minnesota_5-tiny.ppm"); //open file
    std::string reader;

    std::string type;
    std::string height1;
    std::string width1;

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

void average(short int average_list[][3], int &red, int &grn, int &blu)
{
    red = 0;
    blu = 0;
    grn = 0;

    int counter = 0;

    while (average_list[counter][0] != 333 && average_list[counter][1] != 333 && average_list[counter][2] != 333)
    {
        red += average_list[counter][0];
        blu += average_list[counter][1];
        grn += average_list[counter][2];

        counter++;
    }

    if (counter == 0)
    {
        red = random_color();
        blu = random_color();
        grn = random_color();
    }
    else
    {
        red /= counter;
        blu /= counter;
        grn /= counter;
    }
}

float get_distance(int c1[3], int c2[3])
{
    return sqrt(((c1[0] - c2[0]) * (c1[0] - c2[0])) + ((c1[1] - c2[1]) * (c1[1] - c2[1])) + ((c1[2] - c2[2]) * (c1[2] - c2[2])));
}

void update_assignments(int ***image, int ***assignments_list, const int width, const int height, int **means_list, const int k)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float distances[k];
            int c1[3] = {image[j][i][0], image[j][i][1], image[j][i][2]};

            for (int l = 0; l < k; l++)
            {
                int c2[3] = {means_list[l][0], means_list[l][1], means_list[l][2]};

                distances[l] = get_distance(c1, c2);
            }

            int smallest = 0;

            for (int n = 0; n < k; n++)
            {
                if (distances[n] < distances[smallest])
                {
                    smallest = n;
                }
            }

            for(int i = 0; i < k; i++)
            {
                std::cout<<"Means list is as follows in assignments list function:"<<std::endl;
                std::cout<<means_list[i][0]<<std::endl;
                std::cout<<means_list[i][1]<<std::endl;
                std::cout<<means_list[i][2]<<std::endl<<std::endl;

            }

            assignments_list[j][i][0] = smallest;
        }
    }
}

void update_means(int ***image, int ***assignments_list, const int width, const int height, int **means_list, const int k, const int MAX_SIZE)
{
    short int average_list[MAX_SIZE][3];
    int counter = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        average_list[i][0] = 333;
        average_list[i][1] = 333;
        average_list[i][2] = 333;
    }

    for (int i = 0; i < k; i++)
    {

        for (int n = 0; n < height; n++)
        {
            for (int j = 0; j < width; j++)
            {
                if (assignments_list[j][n][0] == i)
                {
                    average_list[counter][0] = image[j][n][0];
                    average_list[counter][1] = image[j][n][1];
                    average_list[counter][2] = image[j][n][2];
                }
            }
        }

        int red, blu, grn = 0;

        average(average_list, red, blu, grn);

        means_list[i][0] = red;
        means_list[i][1] = blu;
        means_list[i][2] = grn;
    }
}

void label(int ***image, int ***assignments_list, int **means_list, const int width, const int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int index = assignments_list[j][i][0];

            // std::cout<<image[j][i][0]<<" ";
            // std::cout<<image[j][i][1]<<" ";
            // std::cout<<image[j][i][2]<<" ";

            image[j][i][0] = means_list[index][0];
            image[j][i][1] = means_list[index][1];
            image[j][i][2] = means_list[index][2];

            std::cout<<image[j][i][0]<<" ";
            std::cout<<image[j][i][1]<<" ";
            std::cout<<image[j][i][2]<<" ";
        }
    }
}

void save_ppm(const std::string &filename, int ***image, const int width, const int height)
{
    std::ofstream outFile;
    outFile.open(filename);

    if (outFile.is_open())
    {
        outFile << "P3\n";
        outFile << width << " " << height << std::endl;
        outFile << "255\n";

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                outFile << image[j][i][0] << " " << image[j][i][1] << " " << image[j][i][2] << " ";
            }
        }
    }

    outFile.close();
}