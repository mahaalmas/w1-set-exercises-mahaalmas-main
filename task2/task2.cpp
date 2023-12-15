#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "task2-functions.h"

// ***********************
// DO NOT CHANGE THIS FILE
// ***********************

int main(int argc, char* argv[])
{
    //Read the command line
    if (argc != 2) {
        cerr << "Filename missing" << endl;
        return -1;
    }
    string strFile = argv[1];

    //Read a vector of points from the file
    vector<Point> points = readDataPoints(strFile);

    //Report on how many points were found
    cout << points.size() << endl;

    //Display all points (on separate lines)
    for (unsigned int n = 0; n < points.size(); n++) {
        displayPoint(points[n]);
    }

    //Get and display the area
    if (points.size() >= 3) {
        double area = areaOfPolygon(points);
        double circ = circumferenceOfPolygon(points);
        cout.precision(1);
        cout << std::fixed;
        cout << area << endl;
        cout << circ << endl;
    }
    else {
        cerr << "There must be at least 3 data points" << endl;
        return -1;
    }
   
    return 0;
}

