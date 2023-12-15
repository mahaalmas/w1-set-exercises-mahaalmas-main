#include "task3_functions.h"
using namespace std;

int main(int argc, char* argv[])
{
    //Read the command line
    if (argc != 2) {
        cout << "Expects a filename as an command line argument" << endl;
        return -1;
    }
    string file = string(argv[1]);

    //Analyse the file
    string location = findCorners(file);
    if (location.empty()) {
        cerr << "Failed" << endl;
        return -1;
    }
    //Write results to the terminal
    cout << location;
        
    return 0;
}

// ***********************
// DO NOT CHANGE THIS FILE
// ***********************
