// confusing password v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Yuliya Vaskiv
// created: 5/25/2021
// v2 - last updated 7/10/2021
// v3 - last updated 8/25/2021
// 
// this program uses array to store numbers.
// the app promts user to put desired even set of numbers,
// those numbers are stored in the array.
// 
// the app uses forst array and by arrangement 
// create new set of numbers gthat reads every second number in array:
// 
// old set    ->     new set
// 1 2 3 4    ->     2 4 4 4
//            -> write 1 time 2s and 3 times 4s
// 
// 

#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"


//global variables
const int ARRAY_SIZE = 500;

//===============================================================
// 
//function that sispalys 'menu'
int intro() {
    int num;
    cout << "enter num of numbers: ";
    cin >> num;

    return num;
}

//==============================================================
// 
//function that stores value into the array
void askNum(int listN[], int& k) {
    int userN;

    if (k >= ARRAY_SIZE) {
        cout << "error......";
    }

    else {
        //stores value into specific place in array
        for (int i = 0; i < k; i++) {
            cout << "enteer " << i + 1 << " number: ";
            cin >> userN;
            listN[i] = userN; //value -> placement
        }
    }

}


//====================================================================
// 
//function that rewrites array 
int readArray(int l[], int n, int newL[]) {

    int nNew = 0; //value for the length of new array

    cout << "................... ";

    //looks into placemnent in the array
    for (int i = 0; i < n; i++) {

        //if array placemnt is divisible by two
        if (i % 2 != 0)
        {
            //writes repeated number of number that is divisible by 2
            // and repeat it depending on a previous number
            for (int p = 1; p <= l[i - 1]; p++) {
                //cout << l[i]; //try1
                newL[nNew] = l[i];

                nNew++; //constantly moves into new place in array
            }
        }

        //number is not divisible by 2
        else {
            //cout << "_"; //prints blank
        }

    }
    return nNew;
}



//============================================================
// 
//
int main()
{
    //variables
    int NUM[ARRAY_SIZE];
    int newNUM[ARRAY_SIZE];
    int number; //number that will be entered

    char userCh = 'y';
    int lineCount = 1;

    const string FILE_NAME = "RewrittenCode.txt";
    ofstream outFile;
    outFile.open(FILE_NAME);
    int newNumber;

    const int COLMFT = 10;
    const int COLMFT1 = 20;
    const int COLMFT2 = 100;

    if (!outFile.is_open())
    {
        cout << "unable to create following file: " << FILE_NAME;
    }

    else
    {
        while (outFile.good()) {
            
            outFile << setw(COLMFT) << left << "Round #";
            outFile << setw(COLMFT1) << left << "old set of numbers";
            outFile << setw(COLMFT2) << right << "new set of numbers";

            while (userCh == 'y')
            {
                number = intro();

                while (number % 2 != 0) {
                    cout << "\nworks only with even numbers. Try again: ";
                    number = intro();
                }

                askNum(NUM, number);

                newNumber = readArray(NUM, number, newNUM);



                outFile << endl << setw(COLMFT) << left << lineCount;


                cout << "\nold set of numbers: ";

                //outFile << setw(COLMFT1 - number) << left;
                
                for (int i1 = 0; i1 < number; i1++) {
                    cout << " " << NUM[i1];
                    outFile << NUM[i1];
                }

                // fix column <<<<<<<<<<<<<<======================== problem
                cout << "\nnew set of numbers: ";
                outFile << setw(COLMFT2) << right;
                for (int i2 = 0; i2 < newNumber; i2++) {
                    cout << " " << newNUM[i2];
                    outFile << newNUM[i2];
                }

                cout << "\ndo you want to continue (y/n): ";
                cin >> userCh;


                lineCount++;



            }
            
            outFile.close();

        }

    }
}
//=====================================================================

