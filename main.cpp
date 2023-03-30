#include <iostream>
#include "tools.h"
#include "Stack_2D.h"
using namespace std;

int menu(int);
void stack_2d();
float matrix_file(string);

int main()
{
    do
    {
        cout << endl;
        cout << "\nProgramming Project 1";
        cout << "\n" << string(50, char(205));
        cout << "\n1. Enter matrices with CLI";
        cout << "\n2. Enter matrices from file";
        cout << "\n0. Exit";
        cout << "\n" << string(50, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 2);
        //int size = inputInteger("Please enter the size for both arrays (2-100): ", 2, 100);

        switch(option)
        {
            case 0: exit(1); break;
            case 1:
            {
                int size = inputInteger(
                        "Please enter the size for both arrays (2-100): ", 2, 100);
                menu(size);
                break;
            }
            case 2:
            {
                string file = inputFile(
                        "Please enter the name of the file "
                        "(Make sure the row and column size is in the first "
                        "line followed by the elements of the matrix): ");
                matrix_file(file);
                break;
            }
            default:
                cout << "\t\tERROR - Invalid option. Please re-enter.";
                break;
        }
        break;
    }while(true);


}

int menu(int size) {
    do {
            cout << endl;
            cout << "\nProgramming Project 1";
            cout << "\n" << string(50, char(205));
            cout << "\n1. Using a regular stack dynamic 2D array";
            cout << "\n2. Pointer to pointer as allocated memory using new";
            cout << "\n3. Pointer to pointer as private data";
            cout << "\n" << string(50, char(196));
            cout << "\n0. Exit";
            cout << "\n" << string(50, char(205)) << "\n";
            int option = inputInteger("Option: ", 0, 2);
        switch (option)
        {
            case 0: exit(1); break;
            case 1: void stack_2d(); break;

            case 2:

                break;
            case 3:

                break;
            default:
                cout << "\t\tERROR - Invalid option. Please re-enter.";
                break;
        }
        cout << "\n";
        system("pause");

    }while(true);
    return 0;
}

void stack_2d(){}

float matrix_file(string file_name)
{

    ifstream file(file_name);

    // read the first matrix
    vector<vector<int>> matrix1 = read_matrix(file);

    // read the second matrix
    vector<vector<int>> matrix2 = read_matrix(file);


}