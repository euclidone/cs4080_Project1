#include <iostream>
#include "tools.h"
#include "Stack_2D.cpp"
#include "Double_Pointer.cpp"
#include "Private_DPointer.cpp"
#include <chrono>
#include <tuple>
#include <iomanip>
using namespace std;
using namespace chrono;

void secondary_menu(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int);
void option1(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size);
void option2(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size);
void option3(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size);
void test_all_mul_ops();
array <float, 3> test_files(string file_name);


int main()
{
    do
    {
        cout << "\nProgramming Project 1";
        cout << "\n" << string(35, char(205));
        cout << "\nChoose your method of input.";
        cout << "\n" << string(35, char(205));
        cout << "\n1. Enter matrices with CLI";
        cout << "\n2. Enter matrices from file";
        cout << "\n3. Test all multiplication programs";
        cout << "\n0. Exit";
        cout << "\n" << string(35, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 3);
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
                file = R"(C:\Users\Angel\CLionProjects\cs4080_individual_project\)" + file;

                pair<vector<vector<float>>, vector<vector<float>>> matrices = readMatricesFromFile(file);
                vector<vector<float>> v1 = matrices.first;
                vector<vector<float>> v2 = matrices.second;

                int size = v1.size();

                float matrix1[MAX_SIZE][MAX_SIZE];
                float matrix2[MAX_SIZE][MAX_SIZE];
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        matrix1[i][j] = v1[i][j];
                        matrix2[i][j] = v2[i][j];
                    }
                }
                secondary_menu(matrix1, matrix2, size);
                break;
            }
            case 3: test_all_mul_ops(); break;
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
            cout << "\nChoose what Matrix program you wish to see.";
            cout << "\n" << string(51, char(205));
            cout << "\n1. Using a regular stack dynamic 2D array";
            cout << "\n2. Pointer to pointer as allocated memory using new";
            cout << "\n3. Pointer to pointer as private data";
            cout << "\n" << string(51, char(196));
            cout << "\n4. Enter new arrays";
            cout << "\n" << string(51, char(196));
            cout << "\n0. Exit";
            cout << "\n" << string(51, char(205)) << "\n";
            int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1: option1(matrix1, matrix2, size); break;
            case 2: option2(matrix1, matrix2, size); break;
            case 3: option3(matrix1, matrix2, size); break;
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
        cout << "\n" << string(43, char(205));
        cout << "\n1. Adding Two Matrices";
        cout << "\n2. Subtracting Two Matrices";
        cout << "\n3. Multiplying Two Matrices";
        cout << "\n" << string(43, char(196));
        cout << "\n4. Enter new arrays";
        cout << "\n" << string(43, char(196));
        cout << "\n0. Exit";
        cout << "\n" << string(43, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1:
            {
                Stack_2D stack1(size, size);
                Stack_2D stack2(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        stack1.push(i, j, matrix1[i][j]);
                        stack2.push(i, j, matrix2[i][j]);
                    }
                cout << "\nMatrix 1\n";
                stack1.print(size);

                cout << "\nMatrix 2\n";
                stack2.print(size);

                cout << "\nResult of Operation\n";
                stack1.add(stack2, size).print(size);
                break;
            }
            case 2:
            {
                Stack_2D stack1(size, size);
                Stack_2D stack2(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        stack1.push(i, j, matrix1[i][j]);
                        stack2.push(i, j, matrix2[i][j]);
                    }
                cout << "\nMatrix 1\n";
                stack1.print(size);

                cout << "\nMatrix 2\n";
                stack2.print(size);

                cout << "\nResult of Operation\n";
                stack1.sub(stack2, size).print(size);
                break;
            }
            case 3:
            {
                Stack_2D stack1(size, size);
                Stack_2D stack2(size, size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        stack1.push(i, j, matrix1[i][j]);
                        stack2.push(i, j, matrix2[i][j]);
                    }
                cout << "\nMatrix 1\n";
                stack1.print(size);

                cout << "\nMatrix 2\n";
                stack2.print(size);

                cout << "\nResult of Operation\n";
                stack1.mul(stack2, size).print(size);
                break;
            }
            case 4: main(); break;
            default: cout << "\nERROR - Invalid option. Please re-enter.\n"; break;
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
        cout << "\n" << string(42, char(205));
        cout << "\n1. Adding Two Matrices";
        cout << "\n2. Subtracting Two Matrices";
        cout << "\n3. Multiplying Two Matrices";
        cout << "\n" << string(42, char(196));
        cout << "\n4. Enter new arrays";
        cout << "\n" << string(42, char(196));
        cout << "\n0. Exit";
        cout << "\n" << string(42, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1:
            {
                Double_Pointer pointer_arr1(size);
                Double_Pointer pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        pointer_arr1[i][j] = matrix1[i][j];
                        pointer_arr2[i][j] = matrix2[i][j];
                    }
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Double_Pointer pointer_arr3 = pointer_arr1.add(pointer_arr1, pointer_arr2, size);
                cout << "\nResult of Operation\n";
                pointer_arr3.print();
                break;
            }
            case 2:
            {
                Double_Pointer pointer_arr1(size);
                Double_Pointer pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        pointer_arr1[i][j] = matrix1[i][j];
                        pointer_arr2[i][j] = matrix2[i][j];
                    }
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Double_Pointer pointer_arr3 = pointer_arr1.sub(pointer_arr1, pointer_arr2, size);
                cout << "\nResult of Operation\n";
                pointer_arr3.print();
                break;
            }
            case 3:
            {
                Double_Pointer pointer_arr1(size);
                Double_Pointer pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        pointer_arr1[i][j] = matrix1[i][j];
                        pointer_arr2[i][j] = matrix2[i][j];
                    }
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Double_Pointer pointer_arr3 = pointer_arr1.mul(pointer_arr1, pointer_arr2, size);
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

void option3(float matrix1[][MAX_SIZE], float matrix2[][MAX_SIZE], int size)
{
    do {
        cout << endl;
        cout << "\nArithmetic Operations - Pointer to Pointer as Private Data";
        cout << "\n" << string(58, char(205));
        cout << "\n1. Adding Two Matrices";
        cout << "\n2. Subtracting Two Matrices";
        cout << "\n3. Multiplying Two Matrices";
        cout << "\n" << string(58, char(196));
        cout << "\n4. Enter new arrays";
        cout << "\n" << string(58, char(196));
        cout << "\n0. Exit";
        cout << "\n" << string(58, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 4);
        switch (option)
        {
            case 0: exit(1); break;
            case 1:
            {
                Matrix pointer_arr1(size);
                Matrix pointer_arr2(size);
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                    {
                        pointer_arr1[i][j] = matrix1[i][j];
                        pointer_arr2[i][j] = matrix2[i][j];
                    }
                cout << "\nMatrix 1\n";
                pointer_arr1.print();

                cout << "\nMatrix 2\n";
                pointer_arr2.print();

                Matrix pointer_arr3 = pointer_arr1 + pointer_arr2;
                cout << "\nResult of Operation\n";
                pointer_arr3.print();
                break;
            }
            case 2:
            {
                {
                    Matrix pointer_arr1(size);
                    Matrix pointer_arr2(size);
                    for (int i = 0; i < size; i++)
                        for (int j = 0; j < size; j++)
                        {
                            pointer_arr1[i][j] = matrix1[i][j];
                            pointer_arr2[i][j] = matrix2[i][j];
                        }
                    cout << "\nMatrix 1\n";
                    pointer_arr1.print();

                    cout << "\nMatrix 2\n";
                    pointer_arr2.print();

                    Matrix pointer_arr3 = pointer_arr1 - pointer_arr2;
                    cout << "\nResult of Operation\n";
                    pointer_arr3.print();
                    break;
                }
            }
            case 3:
            {
                {
                    Matrix pointer_arr1(size);
                    Matrix pointer_arr2(size);
                    for (int i = 0; i < size; i++)
                        for (int j = 0; j < size; j++)
                        {
                            pointer_arr1[i][j] = matrix1[i][j];
                            pointer_arr2[i][j] = matrix2[i][j];
                        }
                    cout << "\nMatrix 1\n";
                    pointer_arr1.print();

                    cout << "\nMatrix 2\n";
                    pointer_arr2.print();

                    Matrix pointer_arr3 = pointer_arr1 * pointer_arr2;
                    cout << "\nResult of Operation\n";
                    pointer_arr3.print();
                    break;
                }
            }
            case 4: main(); break;
            default: cout << "\nERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    }while(true);
}

void test_all_mul_ops()
{
    do {
        cout << "\nChoose size of matrices to test";
        cout << "\n" << string(48, char(205));
        cout << "\n1. Test multiplication 20, 40, 60, 80, 100 sizes";
        cout << "\n" << string(48, char(196));
        cout << "\n2. Enter new arrays";
        cout << "\n" << string(48, char(196));
        cout << "\n0. Exit";
        cout << "\n" << string(48, char(205)) << "\n";
        int option = inputInteger("Option: ", 0, 2);
        switch (option)
        {
            case 0: exit(1); break;
            case 1:
            {
                string base = R"(C:\Users\Angel\CLionProjects\cs4080_individual_project\)";
                string size20 = base + "20x20.txt", size40 = base + "40x40.txt", size60 = base + "60x60.txt",
                size80 = base + "80x80.txt", size100 = base + "100x100.txt";
                string names[] =  {size20, size40, size60, size80, size100};
                string sizes[] = {" 20", " 40"," 60"," 80", "100"};

                array<array<float, 3>, 5> times{};

                for(int i = 0; i < 5; i++)
                {
                    times[i] = test_files(names[i]);

                }
                cout << setw(50) << "Times in Nanoseconds" << endl;
                cout << setw(6) << "sizes" << setw(17) << "Stack Dynamic" << setw(22)
                << "Pointer to Pointer" <<setw(42) << "Pointer to Pointer with Private Data\n";
                for(int i = 0; i < 5; i++)
                {
                    cout << setw(5) << sizes[i] << ": " << setw(12);
                    for(int j = 0; j < 3; j++)
                        cout << times[i][j] << setw(18);
                    cout << endl;
                }
                break;
            }
            case 2: main(); break;
            default: cout << "\nERROR - Invalid option. Please re-enter."; break;
        }
    }while(true);
}

array <float, 3> test_files(string file_name)
{
    pair<vector<vector<float>>, vector<vector<float>>> matrices1 = readMatricesFromFile(file_name);
    vector<vector<float>> v1 = matrices1.first;
    vector<vector<float>> v2 = matrices1.second;

    int size = v1.size();

    Stack_2D stack1(size, size);
    Stack_2D stack2(size, size);

    Double_Pointer pointer_arr1(size);
    Double_Pointer pointer_arr2(size);

    Matrix priv_pointer_arr1(size);
    Matrix priv_pointer_arr2(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            stack1.push(i, j, v1[i][j]);
            stack2.push(i, j, v2[i][j]);

            pointer_arr1[i][j] = v1[i][j];;
            pointer_arr2[i][j] = v2[i][j];

            priv_pointer_arr1[i][j] = v1[i][j];;
            priv_pointer_arr2[i][j] = v2[i][j];
        }
    }
    auto start_time = high_resolution_clock::now();
    stack1.mul(stack2, size);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end_time - start_time);

    auto start_time2 = high_resolution_clock::now();
    Double_Pointer pointer_arr3 = pointer_arr1.mul(pointer_arr1, pointer_arr2, size);
    auto end_time2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end_time2 - start_time2);

    auto start_time3 = high_resolution_clock::now();
    Matrix priv_pointer_arr3 = priv_pointer_arr1 * priv_pointer_arr2;
    auto end_time3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(end_time3 - start_time3);

    return {static_cast<float>(duration.count()),
            static_cast<float>(duration2.count()),
            static_cast<float>(duration3.count())};
}

