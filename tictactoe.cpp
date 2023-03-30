#include <iostream>
#include <conio.h>
using namespace std;
char grid[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}};
void printgrid();
void check(string coordinate);
string player1();
string player2();
string position1;
string position2;
bool checkRows(char symbol);
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
int count = 0;
main()
{
    int row = 3, col = 3;
    while (true)
    {
        system("cls");
        printgrid();

        if (count % 2 == 0)
        {
            string index = player1();
            check(index);
        }
        else
        {
            string index = player2();
            check(index);
        }
        if (checkRows('X') || checkColumns('X') || checkDiagonals('X'))
        {
            cout << "Player  1 Win";
            break;
        }
        else if (checkRows('O') || checkColumns('O') || checkDiagonals('O'))
        {
            cout << "Player 2 win";
            break;
        }
    }
}

void printgrid()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
string player1()
{
    cout << "Player 1 turn" << endl;
    cout << "Enter your position: ";
    cin >> position1;
    return position1;
}

string player2()
{
    cout << "Player 2 turn" << endl;
    cout << "Enter your position: ";
    cin >> position2;
    return position2;
}
void check(string coordinate)
{
    int row, col;
    if (coordinate[0] == 'A')
    {
        row = 0;
    }
    else if (coordinate[0] == 'B')
    {
        row = 1;
    }
    else if (coordinate[0] == 'C')
    {
        row = 2;
    }
    else
    {
        row = -1;
    }
    if (row >= 0)
    {
        col = coordinate[1] - '0';
        if (col >= 3)
        {
            cout << "Invalid input" << endl;
        }
        else
        {
            if (grid[row][col] == 'O' || grid[row][col] == 'X')
            {
                // flag = false;
                cout << "Error";
            }
            else
            {
                // flag = true;
                if (count % 2 == 0)
                {

                    if (grid[row][col] == '-')
                    {
                        grid[row][col] = 'X';
                    }
                    count++;
                }
                else
                {
                    if (grid[row][col] == '-')
                    {
                        grid[row][col] = 'O';
                    }
                    count++;
                }
            }
        }
    }
    else
    {
        cout << "Invalid entity" << endl;
    }
}

bool checkRows(char symbol)
{
    int count = 0;
    for (int row = 0; row < 3; row = row + 1)
    {
        count = 0;
        for (int col = 0; col < 3; col = col + 1)
        {
            if (grid[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == 3)
        {
            return 1;
        }
    }
    return 0;
}

bool checkColumns(char symbol)
{
    int count = 0;
    for (int col = 0; col < 3; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < 3; row = row + 1)
        {
            if (grid[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == 3)
        {
            return 1;
        }
    }
    return 0;
}

bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < 3; idx = idx + 1)
    {
        if (grid[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == 3)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < 3; row++, col--)
    {
        if (grid[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == 3)
    {
        return 1;
    }
    return 0;
}
