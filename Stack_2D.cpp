//
// Created by Angel on 3/29/2023.
//
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;

class Stack_2D{
private:
    int num_rows, num_cols;
    vector<vector<float>> arr;

public:
    Stack_2D(int rows,int cols)
    {
        num_rows = rows;
        num_cols = cols;
        arr.resize(num_rows);
        for(int i = 0; i < num_rows; i++)
            arr[i].resize(num_cols);
    }
    Stack_2D()
    {
        num_rows = 0;
        num_cols = 0;
    }

    void push(int row, int col, float val)
    {
        arr[row][col] = val;
    }
    float pop(int row, int col)
    {
        return arr[row][col];
    }
    void print()
    {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(Stack_2D other, int size)
    {
        Stack_2D result(size, size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float x = pop(i,j) + other.pop(i,j);
                result.push(i,j,x);
            }
        }
        result.print();
    }

    void sub(Stack_2D other, int size)
    {
        Stack_2D result(size,size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float x = pop(i,j) - other.pop(i,j);
                result.push(i,j,x);
            }
        }
        result.print();
    }

    void mul(Stack_2D other, int size)
    {
        Stack_2D result(size,size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float x = pop(i,j) * other.pop(i,j);
                result.push(i,j,x);
            }
        }
        result.print();
    }
};