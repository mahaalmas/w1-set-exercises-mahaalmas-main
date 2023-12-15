#include <iostream>
#include <string>
#include "task1-functions.h"
using namespace std;


// ***********************
// DO NOT CHANGE THIS FILE
// ***********************

int main(int argc, char* argv[])
{
    //Read the command line
    if (argc != 3) {
        cout << "Expects 2 arguments" << endl;
        return -1;
    }
    string strS = string(argv[1]);
    string strB = string(argv[2]);

    int S = stoi(strS);
    int B = stoi(strB);

    int E = setEngineMode(S, B);

    return 0;
}
