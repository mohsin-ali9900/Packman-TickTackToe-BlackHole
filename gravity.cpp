#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void Situation(char seen[][5]);
void rotate(char seen[][5],int times);

main()
{
    system("cls");

    char seen[5][5] = {
        {' ', ' ', '#', ' ', '#'},
        {' ', '#', ' ', ' ', ' '},
        {'#', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', '#'},
    };

    rotate(seen,100);
}

void Situation(char seen[][5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < 5; j++)
        {
            cout << seen[i][j] << "\t";
        }
        cout << endl;
    }
}

void rotate(char seen[][5],int times)
{
    char lastRow[5];
    for (int k = 0; k < times; k++)
    {
        system("cls");
        Situation(seen);
        Sleep(500);
        for (int a = 0; a < 5; a++)
        {
            lastRow[a] = seen[4][a];
        }
        for (int i = 4; i >= 0; i--)
        {
            for (int j = 4; j >= 0; j--)
            {
                if (i == 0)
                {
                    seen[i + 1][j] = seen[i][j];
                    seen[i][j] = lastRow[j];
                }
                else
                {
                    if (seen[i][j] == '#')
                    {
                        seen[i + 1][j] = seen[i][j];
                        seen[i][j] = seen[i - 1][j];
                    }
                }
            }
        }
    }
}