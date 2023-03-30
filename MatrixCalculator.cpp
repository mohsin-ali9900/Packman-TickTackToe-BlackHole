#include <iostream>
#include <conio.h>

using namespace std;

string menu();
void header();
void clear();

// Funtion to input the data
void inputData(int array[][3], int size);

// Funtion to show the data
void showData(int array[][3], int size);

// Funtion for the addition of matrix
void add(int array[][3], int array1[][3], int result[][3], int size);

// Funtion for the subtraction of matrix
void subtract(int array[][3], int array1[][3], int result[][3], int size);

// Funtion for the multiplication of matrix
void multiplicate(int array[][3], int array1[][3], int result[][3], int size);

// Funtion for the scalar multiplication of matrix
void scalarMultiplication(int array[][3], int result[][3], int num, int size);

// Funtion for the transpose of matrix
void transpose(int array[][3], int result[][3], int size);

// Funtion to check Diagnol matrix
bool isDiagnol(int array[][3], int size);

// Funtion to check symmetric matric
bool isSymetric(int array[][3], int result[][3], int size);

main()
{
    bool check;
    int size = 3;
    int num;
    int A[size][3];
    int B[size][3];
    int R[size][3];
    system("cls");
    string choice;
    while (choice != "8")
    {
        choice = menu();
        if (choice == "1")
        {
            header();
            cout << "\nEnter elements of first matrix \n";
            inputData(A, size);
            cout << "\nEnter elements of second matrix \n";
            inputData(B, size);
            header();
            cout << "\nElements of first matrix\n";
            showData(A, size);
            cout << "\nElements of second matrix\n";
            showData(B, size);
            add(A, B, R, size);
            cout << "\nSum of matrix is given below\n";
            showData(R, size);
            clear();
        }

        else if (choice == "2")
        {
            header();
            cout << "\nEnter elements of first matrix \n";
            inputData(A, size);
            cout << "\nEnter elements of second matrix \n";
            inputData(B, size);
            header();
            cout << "\nElements of first matrix\n";
            showData(A, size);
            cout << "\nElements of second matrix\n";
            showData(B, size);
            subtract(A, B, R, size);
            cout << "\nSubtraction of matrix is given below\n";
            showData(R, size);
            clear();
        }

        else if (choice == "3")
        {
            header();
            cout << "\nEnter elements of first matrix \n";
            inputData(A, size);
            cout << "\nEnter elements of second matrix \n";
            inputData(B, size);
            header();
            cout << "\nElements of first matrix\n";
            showData(A, size);
            cout << "\nElements of second matrix\n";
            showData(B, size);
            multiplicate(A, B, R, size);
            cout << "\nMultiplication of matrix is given below\n";
            showData(R, size);
            clear();
        }

        else if (choice == "4")
        {
            header();
            cout << "\nEnter elements of the matrix \n";
            inputData(A, size);
            header();
            cout << "\nElements of the matrix\n";
            showData(A, size);
            cout << "\nEnter number you want to multiply : ";
            cin >> num;
            scalarMultiplication(A, R, num, size);
            cout << "\nScalar multiplication of matrix is given below\n";
            showData(R, size);
            clear();
        }

        else if (choice == "5")
        {
            header();
            cout << "\nEnter elements of the matrix \n";
            inputData(A, size);
            header();
            cout << "\nElements of the matrix\n";
            showData(A, size);
            transpose(A, R, size);
            cout << "\nTranspose of matrix is given below\n";
            showData(R, size);
            clear();
        }

        else if (choice == "6")
        {
            header();
            cout << "\nEnter elements of the matrix \n";
            inputData(A, size);
            header();
            cout << "\nElements of the matrix\n";
            showData(A, size);
            check = isDiagnol(A, size);
            if (check == true)
            {
                cout << "\nDiagnol matrix\n";
                clear();
            }
            else
            {
                cout << "\nNot a diagnol matrix\n";
                clear();
            }
        }

        else if (choice == "7")
        {
            header();
            cout << "\nEnter elements of the matrix \n";
            inputData(A, size);
            header();
            cout << "\nElements of the matrix\n";
            showData(A, size);
            transpose(A, R, size);
            check = isSymetric(A, R, size);
            if (check == true)
            {
                cout << "\nIts a Symmetric matrix\n";
                clear();
            }
            else
            {
                cout << "\nIts Not a symmetric matrix\n";
                clear();
            }
        }

        else
        {
            cout << "Invalid entry! ";
            clear();
        }
    }
}

void clear()
{
    cout << "\nPress any key to continue..\n";
    getch();
}

void header()
{
    system("cls");
    cout << "######################################################################################" << endl;
    cout << "##                               MATRIX CALCULATOR                                  ##" << endl;
    cout << "######################################################################################" << endl;
}

string menu()
{
    string option;
    header();
    cout << "__________________________________________" << endl;
    cout << "1.\tAddition" << endl;
    cout << "2.\tSubtraction" << endl;
    cout << "3.\tMultiplication" << endl;
    cout << "4.\tScalar Multiplication" << endl;
    cout << "5.\tTranspose" << endl;
    cout << "6.\tCheck diagnol" << endl;
    cout << "7.\tCheck symmetric" << endl;
    cout << "8.\tExit" << endl;
    cout << ".........................................." << endl;
    cout << "Enter your choice : ";
    cin >> option;
    return option;
}

void inputData(int array[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter element A" << i << j << " : ";
            cin >> array[i][j];
        }
    }
}

void showData(int array[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void add(int array[][3], int array1[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = array[i][j] + array1[i][j];
        }
    }
}

void subtract(int array[][3], int array1[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = array[i][j] - array1[i][j];
        }
    }
}

void multiplicate(int array[][3], int array1[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = array[i][j] * array1[j][i];
        }
    }
}

void scalarMultiplication(int array[][3], int result[][3], int num, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = num * array[i][j];
        }
    }
}

void transpose(int array[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = array[j][i];
        }
    }
}

bool isDiagnol(int array[][3], int size)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (array[i][j] != 0)
                {
                    count1++;
                }
            }
            if (i != j)
            {
                if (array[i][j] == 0)
                {
                    count2++;
                }
            }
        }
    }
    if (count1 == 3 && count2 == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSymetric(int array[][3], int result[][3], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (result[i][j] = array[i][j])
            {
                count++;
            }
        }
    }
    if (count == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}