#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// The data type for a point - do NOT change this
struct Point {
    double x;
    double y;
};

double areaOfPolygon(vector<Point> points);
double circumferenceOfPolygon(vector<Point> points);
void displayPoint(Point p);
vector<Point> readDataPoints(string strFile);

// ****************************************
// DO NOT CHANGE THIS FILE ABOVE THIS POINT
// ****************************************

