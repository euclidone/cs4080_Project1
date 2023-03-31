//
// Created by Angel on 3/31/2023.
//

#include <iostream>
using namespace std;

class Pointers{
private:
    int array_size;
    float **matrix;

public:
    Pointers(int size)
    {
        array_size = size;

        matrix = new float*[array_size];
        for(int i = 0; i < array_size; i++)
            matrix[i] = new float[array_size];
    }

    ~Pointers()
    {
        for(int i = 0; i < array_size; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    void print()
    {
        for(int i = 0; i < array_size; i++)
        {
            for(int j = 0; j < array_size; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    float* operator[](int index) const
    {
        return matrix[index];
    }

    Pointers add(const Pointers& A, const Pointers& B, int size)
    {
        Pointers result(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result.matrix[i][j] = A[i][j] + B[i][j];
        }
        return result;
    }

    Pointers sub(const Pointers& A, const Pointers& B, int size)
    {
        Pointers result(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result.matrix[i][j] = A[i][j] - B[i][j];
        }
        return result;
    }

    Pointers mul(const Pointers& A, const Pointers& B, int size)
    {
        Pointers result(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result.matrix[i][j] = A[i][j] * B[i][j];
        }
        return result;
    }
};
