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

bool inputFile(string input)
{
    ifstream file(input);
    if (file.good())
        return true;
    else
    {
        cout << "\nERROR: Not a valid file.";
        return false;
    }
}

vector<vector<float>> read_matrix(ifstream& file)
{
    int rows, cols;
    file >> rows >> cols;

    vector<vector<float>> matrix(rows, vector<float>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }
    return matrix;
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

void delete_matrix(float **&arr, int size)
{
    for (int i = 0; i < size; i++)
        delete [] arr[i];
    delete [] arr;
}

float** create_arr(int size) 
{
    float** arr = new float*[size];
    for (int i = 0; i < size; i++) 
        arr[i] = new float[size];
    
    return arr;
}

float** convert_arr(float arr[][MAX_SIZE], int size)
{
    float** temp = new float*[size];
    
    for (int i = 0; i < size; i++)
    {
        temp[i] = new float[size];
        for(int j = 0; j < size; j++)
            temp[i][j] = arr[i][j];
    }
    return temp;
}


#endif //CS4080_INDIVIDUAL_PROJECT_TOOLS_H
