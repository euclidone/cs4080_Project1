//
// Created by Angel on 3/29/2023.
//
#include <iostream>
#include <vector>
using namespace std;

class Stack_2D{
public:
    vector<vector<float>> arr;

    Stack_2D(int rows = 0, int cols = 0)
    {
        int num_rows = rows;
        int num_cols = cols;
        arr.resize(num_rows);
        for(int i = 0; i < num_rows; i++)
            arr[i].resize(num_cols);
    }

    void push(int row, int col, float val)
    {
        arr[row][col] = val;
    }

    float pop(int row, int col)
    {
        return arr[row][col];
    }

    void print(int size)
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    Stack_2D add(Stack_2D new_arr, int size)
    {
        Stack_2D result(size, size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float x = pop(i,j) + new_arr.pop(i,j);
                result.push(i,j,x);
            }
        }
        return result;
    }

    Stack_2D sub(Stack_2D new_arr, int size)
    {
        Stack_2D result(size,size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float x = pop(i,j) - new_arr.pop(i,j);
                result.push(i,j,x);
            }
        }
        return result;
    }

    Stack_2D mul(Stack_2D new_arr, int size)
    {
        Stack_2D result(size,size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float x = pop(i,j) * new_arr.pop(i,j);
                result.push(i,j,x);
            }
        }
        return result;
    }
};