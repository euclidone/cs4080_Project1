//
// Created by Angel on 3/29/2023.
//

#include "Stack_2D.h"
#include <iostream>
using namespace std;

Stack_2D::Stack_2D(int rows, int cols) {
    numRows = rows;
    numCols = cols;

    // allocate memory for 2D array
    arr = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        arr[i] = new int[numCols];
    }
}

Stack_2D::~Stack_2D() {
    // free memory for 2D array
    for (int i = 0; i < numRows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Stack_2D::push(int row, int col, int val) {
    // check if row and column are within bounds
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        arr[row][col] = val;
    }
}

int Stack_2D::pop(int row, int col) {
    // check if row and column are within bounds
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        return arr[row][col];
    }
    return -1; // error value
}
