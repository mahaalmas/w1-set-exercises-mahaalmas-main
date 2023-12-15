#include "task3_functions.h"
#include <fstream>
#include <climits> // for INT_MAX and INT_MIN
#include <string>
using namespace std;

string findCorners(std::string filePath)
{
    ifstream file(filePath);
    string line;
    int topLeftRow = INT_MAX, topLeftCol = INT_MAX;
    int bottomRightRow = INT_MIN, bottomRightCol = INT_MIN;

    if (!file.is_open())
    {
        return "Unable to open file: " + filePath;
    }

    int row = 0;
    while (getline(file, line))
    {
        for (int col = 0; col < line.length(); col++)
        {
            if (line[col] == '*')
            {
                topLeftRow = min(topLeftRow, row);
                topLeftCol = min(topLeftCol, col);
                bottomRightRow = max(bottomRightRow, row);
                bottomRightCol = max(bottomRightCol, col);
            }
        }
        row++;
    }

    file.close();

    // Check if the file was empty
    if (topLeftRow == INT_MAX || topLeftCol == INT_MAX)
    {
        return "No '*' found in the file.";
    }

    return "{ \"topLeft\" : [" + to_string(topLeftRow) + "," + to_string(topLeftCol) + "], \"bottomRight\" : [" + to_string(bottomRightRow) + "," + to_string(bottomRightCol) + "] }";
}
}