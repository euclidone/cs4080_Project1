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

const int MAX_SIZE = 100;

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

void get_matrix(float arr[][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter value at [" << i << "][" << j << "]:";
            cin >> arr[i][j];
            cin.ignore();
        }
    }
}

pair<vector<vector<float>>, vector<vector<float>>> readMatricesFromFile(string filename) {
    // Open file for reading
    ifstream file(filename);

    // Read first matrix size
    int size1;
    file >> size1;

    // Read first matrix values
    vector<vector<float>> matrix1(size1, vector<float>(size1));
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1; j++) {
            file >> matrix1[i][j];
        }
    }

    // Read second matrix size
    int size2;
    file >> size2;

    // Read second matrix values
    vector<vector<float>> matrix2(size2, vector<float>(size2));
    for (int i = 0; i < size2; i++) {
        for (int j = 0; j < size2; j++) {
            file >> matrix2[i][j];
        }
    }

    // Close file
    file.close();
    return make_pair(matrix1, matrix2);
}


#endif //CS4080_INDIVIDUAL_PROJECT_TOOLS_H
