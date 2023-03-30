//
// Created by Angel on 3/29/2023.
//
#ifndef CS4080_INDIVIDUAL_PROJECT_TOOLS_H
#define CS4080_INDIVIDUAL_PROJECT_TOOLS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int inputInteger(string prompt, int startRange, int endRange)
{
    int input;
    do
    {
        cout << prompt;
        if (!(cin >> input))
        {
            cout << "ERROR: Invalid input. Must be an integer type.\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
            cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
        else
            break;
    } while (true);
    cin.clear();
    cin.ignore(999, '\n');
    return input;
}
string inputFile(string prompt)
{
    string input = "";

    cout << prompt;

    getline(cin, input);
    ifstream file(input);
    if (file.good())
        return input;
    else
    {
        cout << "\n\tERROR: Not a valid file.";
    }
}

vector<vector<int>> read_matrix(ifstream& file) {
    int rows, cols;
    file >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }
    return matrix;
}

#endif //CS4080_INDIVIDUAL_PROJECT_TOOLS_H
