//
// Created by Angel on 3/31/2023.
//
#include <iostream>
using namespace std;

class Matrix {
private:
    int size;
    float **matrix;

public:
    Matrix(int s)
    {
        size = s;
        matrix = new float *[size];
        for (int i = 0; i < size; i++)
            matrix[i] = new float[size];
    }

    Matrix(const Matrix &new_matrix) 
    {
        size = new_matrix.size;
        matrix = new float *[size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new float[size];
            for (int j = 0; j < size; j++)
                matrix[i][j] = new_matrix.matrix[i][j];
        }
    }

    ~Matrix() 
    {
        for (int i = 0; i < size; i++)
            delete[] matrix[i];

        delete[] matrix;
    }

    float* operator[](int index) const
    {
        return matrix[index];
    }

    void print()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &new_matrix) const 
    {
        Matrix result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                result.matrix[i][j] = matrix[i][j] + new_matrix.matrix[i][j];
        }
        return result;
    }

    Matrix operator-(const Matrix &new_matrix) const
    {
        Matrix result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                result.matrix[i][j] = matrix[i][j] - new_matrix.matrix[i][j];
        }
        return result;
    }

    Matrix operator*(const Matrix &new_matrix) const 
    {
        Matrix result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                result.matrix[i][j] = matrix[i][j] * new_matrix.matrix[i][j];
        }
        return result;
    }
};