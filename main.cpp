#include <iostream>
#include "tools.h"
#include "Stack_2D.cpp"
#include "Pointers.cpp"
#include <fstream>
using namespace std;

void secondary_menu(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int);
void option1(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size);
void option2(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size);

int main()
{
    do
    {
        cout << endl;
        cout << "\nProgramming Project 1";
        cout << "\n" << string(30, char(205));
        cout << "\n1. Enter matrices with CLI";
        cout << "\n2. Enter matrices from file";
        cout << "\n0. Exit";
        cout << "\n" << string(30, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 2);
        switch(option)
        {
            case 0: exit(1); break;
            case 1:
            {
                float matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
                int size = inputInteger("\nEnter the size of both matrices: ", 2, MAX_SIZE);

                cout << "\nMatrix 1\n";
                get_matrix(matrix1,size);

                cout << "\nMatrix 2\n";
                get_matrix(matrix2,size);
                secondary_menu(matrix1, matrix2, size);
                break;
            }
            case 2:
            {
                string file;
                // Make sure the row and column size is in the first line followed by the elements of the matrix
                cout << "Please enter the name of the file: ";
                cin >> file;

                if(!inputFile(file))
                    continue;
                else
                {
                    ifstream file_name(file);
                    vector<vector<float>> matrix1 = read_matrix(file_name);
                    vector<vector<float>> matrix2 = read_matrix(file_name);
                    break;
                }
            }
            default:
                cout << "\t\tERROR - Invalid option. Please re-enter.";
                break;
        }
        break;
    }while(true);


}

void secondary_menu(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size)
{
    do {
            cout << endl;
            cout << "\nProgramming Project 1";
            cout << "\n" << string(52, char(205));
            cout << "\n1. Using a regular stack dynamic 2D array";
            cout << "\n2. Pointer to pointer as allocated memory using new";
            cout << "\n3. Pointer to pointer as private data";
            cout << "\n4. Enter new arrays";
            cout << "\n" << string(52, char(196));
            cout << "\n0. Exit";
            cout << "\n" << string(52, char(205)) << "\n";
            int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1: option1(matrix1, matrix2, size); break;
            case 2: option2(matrix1, matrix2, size); break;
            case 3:

                break;
            case 4: main(); break;
            default:
                cout << "\t\tERROR - Invalid option. Please re-enter.";
                break;
        }
        cout << "\n";
        system("pause");

    }while(true);

}

void option1(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size)
{
    do {
        cout << endl;
        cout << "\nArithmetic Operations - Stack Dynamic Array";
        cout << "\n" << string(28, char(205));
        cout << "\n1. Adding Two Matrices";
        cout << "\n2. Subtracting Two Matrices";
        cout << "\n3. Multiplying Two Matrices";
        cout << "\n4. Enter new arrays";
        cout << "\n" << string(28, char(196));
        cout << "\n0. Exit";
        cout << "\n" << string(28, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1: {
                Stack_2D stack1(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        stack1.push(i, j, matrix1[i][j]);
                cout << "\nMatrix 1\n";
                stack1.print();

                Stack_2D stack2(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        stack2.push(i, j, matrix2[i][j]);
                cout << "\nMatrix 2\n";
                stack2.print();

                cout << "\nResult of Operation\n";
                stack1.add(stack2, size);

                break;
            }
            case 2:
            {
                Stack_2D stack1(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        stack1.push(i, j, matrix1[i][j]);
                cout << "\nMatrix 1\n";
                stack1.print();

                Stack_2D stack2(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        stack2.push(i, j, matrix2[i][j]);
                cout << "\nMatrix 2\n";
                stack2.print();

                cout << "\nResult of Operation\n";
                stack1.sub(stack2, size);
                break;
            }
            case 3:
            {
                Stack_2D stack1(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        stack1.push(i, j, matrix1[i][j]);
                cout << "\nMatrix 1\n";
                stack1.print();

                Stack_2D stack2(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        stack2.push(i, j, matrix2[i][j]);
                cout << "\nMatrix 2\n";
                stack2.print();

                cout << "\nResult of Operation\n";
                stack1.mul(stack2, size);
                break;
            }
            case 4: main(); break;
            default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    }while(true);
}

void option2(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size)
{
    do {
        cout << endl;
        cout << "\nArithmetic Operations - Pointer to Pointer";
        cout << "\n" << string(28, char(205));
        cout << "\n1. Adding Two Matrices";
        cout << "\n2. Subtracting Two Matrices";
        cout << "\n3. Multiplying Two Matrices";
        cout << "\n4. Enter new arrays";
        cout << "\n" << string(28, char(196));
        cout << "\n0. Exit";
        cout << "\n" << string(28, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1:
            {
                Pointers pointer_arr1(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        pointer_arr1[i][j] = matrix1[i][j];
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                Pointers pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        pointer_arr2[i][j] = matrix2[i][j];
                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Pointers pointer_arr3 = pointer_arr1.add(pointer_arr1, pointer_arr2, size);
                cout << "\nResult of Operation\n";
                pointer_arr3.print();

                break;
            }
            case 2:
            {
                Pointers pointer_arr1(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        pointer_arr1[i][j] = matrix1[i][j];
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                Pointers pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        pointer_arr2[i][j] = matrix2[i][j];
                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Pointers pointer_arr3 = pointer_arr1.sub(pointer_arr1, pointer_arr2, size);
                cout << "\nResult of Operation\n";
                pointer_arr3.print();
                break;
            }
            case 3:
            {                Pointers pointer_arr1(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        pointer_arr1[i][j] = matrix1[i][j];
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                Pointers pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        pointer_arr2[i][j] = matrix2[i][j];
                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Pointers pointer_arr3 = pointer_arr1.mul(pointer_arr1, pointer_arr2, size);
                cout << "\nResult of Operation\n";
                pointer_arr3.print();
                break;
            }
            case 4: main(); break;
            default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    }while(true);
}

