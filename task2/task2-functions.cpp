#include "task2-functions.h"
#include <fstream>
#include <cmath> // Added for sqrt function
using namespace std;

/////////////////////////////////////// DO NOT MODIFY THE FOLLOWING ///////////////////////////////////////

// This is a tested function to calculate and return the area of a polygon with corner coordinates in the array points.
// You may call this from within this file
// You cannot call this directly from other files
// Do NOT change this function
static double areaOfPolygon_v1(Point points[], int n) {
    double area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
        j = i;
    }
    return abs(area / 2.0);
}

// This is a tested function to calculate and return the length of a line between points p1 and p2
// You may call this from within this file
// You cannot call this directly from other files
// Do NOT change this function
static double distanceBetweenPoints(Point p1, Point p2) {
    double xd = p1.x - p2.x;
    double yd = p1.y - p2.y;
    double d = sqrt(xd * xd + yd * yd); // Good ol' Pythagoras
    return d;
}

// Display a point in the terminal
// Do NOT change this function
void displayPoint(Point p) {
    cout.precision(1);
    cout << std::fixed;
    cout << "(" << p.x << "," << p.y << ")" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// YOUR SOLUTION STARTS HERE ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

double areaOfPolygon(vector<Point> points) {
    double area = 0.0;
    int n = points.size();
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
        j = i;
    }
    return abs(area / 2.0);
}

double circumferenceOfPolygon(vector<Point> points) {
    double circumference = 0.0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        circumference += distanceBetweenPoints(points[i], points[(i + 1) % n]);
    }
    return circumference;
}

vector<Point> readDataPoints(string strFile) {
    vector<Point> points;
    ifstream infile(strFile);
    if (!infile) {
        cerr << "Unable to open file: " << strFile << endl;
        exit(1);
    }
    string line;
    int lineNumber = 0;

    // Read lines until an opening brace '{' is found
    while (getline(infile, line)) {
        lineNumber++;

        // Skip lines until an opening brace '{' is found
        if (line.find('{') != string::npos) {
            break;
        }
    }

    while (getline(infile, line)) {
        lineNumber++;

        // Break if a closing brace '}' is found
        if (line.find('}') != string::npos) {
            break;
        }

        // Display the line being read (for debugging purposes)
        cout << "Reading line " << lineNumber << ": " << line << endl;

        stringstream ss(line);
        Point p;

        // Modified: Input validation to ensure correct format
        if (!(ss >> p.x) || !(ss >> p.y)) {
            cerr << "Error reading point from file: " << strFile << " at line: " << lineNumber << endl;
            exit(1);
        }

        points.push_back(p);
    }

    return points;
}