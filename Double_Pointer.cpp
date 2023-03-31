//
// Created by Angel on 3/31/2023.
//

#include <iostream>
using namespace std;

class Double_Pointer{
private:
    int array_size;
    float **matrix;

public:
    Double_Pointer(int size)
    {
        array_size = size;

        matrix = new float*[array_size];
        for(int i = 0; i < array_size; i++)
            matrix[i] = new float[array_size];
    }

    ~Double_Pointer()
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

    Double_Pointer add(const Double_Pointer& A, const Double_Pointer& B, int size)
    {
        Double_Pointer result(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result.matrix[i][j] = A[i][j] + B[i][j];
        }
        return result;
    }

    Double_Pointer sub(const Double_Pointer& A, const Double_Pointer& B, int size)
    {
        Double_Pointer result(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result.matrix[i][j] = A[i][j] - B[i][j];
        }
        return result;
    }

    Double_Pointer mul(const Double_Pointer& A, const Double_Pointer& B, int size)
    {
        Double_Pointer result(size);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                result.matrix[i][j] = A[i][j] * B[i][j];
        }
        return result;
    }
};
