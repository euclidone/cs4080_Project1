//
// Created by Angel on 3/29/2023.
//

#ifndef CS4080_INDIVIDUAL_PROJECT_STACK_2D_H
#define CS4080_INDIVIDUAL_PROJECT_STACK_2D_H

#include <iostream>
using namespace std;

class Stack_2D {
private:
    int numRows, numCols;
    int **arr; // 2D array pointer

public:
    Stack_2D(int rows, int cols);

    ~Stack_2D();

    void push(int row, int col, int val);

    int pop(int row, int col);
};

#endif //CS4080_INDIVIDUAL_PROJECT_STACK_2D_H
