#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void header();
void maze();
void clear();
string option();
void gameRun();
void gotoxy(int x, int y);
char GetCharAtxy(short int x, short int y);
void printPac();
void erasePac();
void movePacRight();
void movePacLeft();
void movePacUp();
void movePacDown();
void printGhost(int x, int y);
void clearGhost(int x, int y);
void moveGhostHor();
void moveGhostVer();
void moveChasingGhost();
void printScore();
void printLives();
char nextlocation;
int Px = 60;
int Py = 10;
int Gx1 = 6;
int Gy1 = 15;
int Gx2 = 78;
int Gy2 = 3;
float Gx3 = 60;
float Gy3 = 20;
int score;
int lives = 3;
char key;
string direction = "right";
string direction2 = "down";
main()
{
    string choice;
    while (true)
    {
        system("cls");
        header();
        choice = option();
        if (choice == "1")
        {
            gameRun();
        }
        else if (choice == "2")
        {
            break;
        }
        else
        {
            cout << "Invalid entity! ";
            clear();
        }
    }
}

void header()
{
    cout << "======================================" << endl;
    cout << "               PACMAN                 " << endl;
    cout << "......................................" << endl;
}
void clear()
{
    cout << "Enter any key to continue...";
    getch();
    system("cls");
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char GetCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
                                                                                            : ' ';
}

string option()
{
    string choice;
    cout << "____________________________________" << endl;
    cout << "1.\tStart Game" << endl;
    cout << "2.\tEnd Game" << endl;
    cout << "...................................." << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

void gameRun()
{
    system("cls");
    maze();
    printPac();
    printGhost(Gx1, Gy1);
    printGhost(Gx2, Gy2);
    while (true)
    {
        printScore();
        printLives();
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePacRight();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacLeft();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePacDown();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePacUp();
        }
        if (lives <= 0)
        {
            system("cls");
            lives = 3;
            score = 0;
            cout << "___________________________" << endl;
            cout << "          Game Over        " << endl;
            cout << "===========================" << endl;
            cout << "Enter a key to continue : ";
            cin >> key;
            break;
        }
        moveGhostHor();
        moveGhostVer();
        moveChasingGhost();
        Sleep(100);
    }
}
void maze()
{
    cout << " ##################################################################################   " << endl;
    cout << " ||.. ..............................................................   .....     ||   " << endl;
    cout << " ||.. %%%%%%%%%%%%%%%%%          ...          %%%%%%%%%%%%%%%  |%|..    %%%      ||   " << endl;
    cout << " ||..       |%|     |%|       |%|...           |%|        |%|  |%|..    |%|      ||   " << endl;
    cout << " ||..       |%|     |%|       |%|...           |%|        |%|  |%|..    |%|      ||   " << endl;
    cout << " ||..       %%%%%%%%%%%   ..  |%|...           %%%%%%%%%%%%%%     ..    %%%.     ||   " << endl;
    cout << " ||..    G  |%|           ..  |%|...           .............. |%| ..       .     ||   " << endl;
    cout << " ||..       %%%%%%%%%%%   ..  |%|...           %%%%%%%%%%%%   |%| ..    %%%.     ||   " << endl;
    cout << " ||..               |%|.  ..                   |%|......      |%| ..    |%|.     ||   " << endl;
    cout << " ||..     ......... |%|.  ..                   |%|......|%|       ..    |%|.     ||   " << endl;
    cout << " ||..|%|  |%|%%%|%|.|%|. |%|                      ......|%|       ..|%| |%|.     ||   " << endl;
    cout << " ||..|%|  |%|   |%|..    %%%%%%%%%%%%%%%%%%       ......|%|        .|%|.         ||   " << endl;
    cout << " ||..|%|  |%|   |%|..                ...|%|          %%%%%%       . |%|.         ||   " << endl;
    cout << " ||..|%|            .                ...|%|                   |%| ..|%|.         ||   " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%             ...|%|%%%%%%%%%%%%%%     |%| ..|%|%%%%      ||   " << endl;
    cout << " ||                                                           |%| ..........     ||   " << endl;
    cout << " ||    ...................................................          ........     ||   " << endl;
    cout << " ||..|%|  |%|  |%|..     %%%%%%%%%%%%%%      ..........|%|    |%| ..|%|.         ||   " << endl;
    cout << " ||..|%|  |%|  |%|..             ...|%|           %%%%%%%%    |%| ..|%|.         ||   " << endl;
    cout << " ||..|%|           .             ...|%|                       |%| ..|%|.         ||   " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%%        ...|%|%%%%%%%%%%%%%%%        |%| ..|%|%%%%      ||   " << endl;
    cout << " ||.....................................................      |%| .........      ||   " << endl;
    cout << " ||  ...................................................             ......      ||   " << endl;
    cout << " ##################################################################################   " << endl;
}

void printPac()
{
    gotoxy(Px, Py);
    cout << "P";
}
void erasePac()
{
    gotoxy(Px, Py);
    cout << " ";
}

void printGhost(int x, int y)
{
    gotoxy(x, y);
    cout << "G";
}

void clearGhost(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void movePacRight()
{
    nextlocation = GetCharAtxy(Px + 1, Py);
    if (nextlocation == ' ')
    {
        erasePac();
        Px = Px + 1;
        printPac();
    }
    if (nextlocation == 'G')
    {
        erasePac();
        score = 0;
        Px = 60;
        Py = 10;
        printPac();
        lives--;
    }
    if (nextlocation == '.')
    {
        erasePac();
        Px = Px + 1;
        printPac();
        score++;
    }
}

void movePacLeft()
{
    nextlocation = GetCharAtxy(Px - 1, Py);

    if (nextlocation == ' ')
    {
        erasePac();
        Px = Px - 1;
        printPac();
    }
    if (nextlocation == 'G')
    {
        erasePac();
        score = 0;
        Px = 60;
        Py = 10;
        printPac();
        lives--;
    }
    if (nextlocation == '.')
    {
        erasePac();
        Px = Px - 1;
        printPac();
        score++;
    }
}

void movePacUp()
{
    nextlocation = GetCharAtxy(Px, Py - 1);

    if (nextlocation == ' ')
    {
        erasePac();
        Py = Py - 1;
        printPac();
    }
    if (nextlocation == 'G')
    {
        erasePac();
        score = 0;
        Px = 60;
        Py = 10;
        printPac();
        lives--;
    }
    if (nextlocation == '.')
    {
        erasePac();
        Py = Py - 1;
        printPac();
        score++;
    }
}

void movePacDown()
{
    nextlocation = GetCharAtxy(Px, Py + 1);

    if (nextlocation == ' ')
    {
        erasePac();
        Py = Py + 1;
        printPac();
    }
    if (nextlocation == 'G')
    {
        erasePac();
        score = 0;
        Px = 60;
        Py = 10;
        printPac();
        lives--;
    }
    if (nextlocation == '.')
    {
        erasePac();
        Py = Py + 1;
        printPac();
        score++;
    }
}

void moveGhostHor()
{
    if (direction == "right")
    {
        char nextlocation = GetCharAtxy(Gx1 + 1, Gy1);
        if ((nextlocation == '%' || nextlocation == '|'))
        {
            direction = "left";
        }

        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearGhost(Gx1, Gy1);
            Gx1++;
            printGhost(Gx1, Gy1);
        }

        else if (nextlocation == 'P')
        {
            erasePac();
            score = 0;
            Px = 60;
            Py = 10;
            Px = Px + 1;
            printPac();
            lives--;
        }
    }
    if (direction == "left")
    {
        char nextlocation = GetCharAtxy(Gx1 - 1, Gy1);
        if ((nextlocation == '%' || nextlocation == '|'))
        {
            direction = "right";
        }

        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearGhost(Gx1, Gy1);
            Gx1--;
            printGhost(Gx1, Gy1);
        }

        else if (nextlocation == 'P')
        {
            erasePac();
            score = 0;
            Px = 60;
            Py = 10;
            Px = Px + 1;
            printPac();
            lives--;
        }
    }
}

void moveGhostVer()
{
    if (direction2 == "down")
    {
        char nextlocation = GetCharAtxy(Gx2, Gy2 + 1);
        if ((nextlocation == '#'))
        {
            direction2 = "up";
        }

        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearGhost(Gx2, Gy2);
            Gy2++;
            printGhost(Gx2, Gy2);
        }
        else if (nextlocation == 'P')
        {
            erasePac();
            score = 0;
            Px = 60;
            Py = 10;
            Px = Px + 1;
            printPac();
            lives--;
        }
    }
    if (direction2 == "up")
    {
        char nextlocation = GetCharAtxy(Gx2, Gy2 - 1);
        if ((nextlocation == '#'))
        {
            direction2 = "down";
        }

        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearGhost(Gx2, Gy2);
            Gy2--;
            printGhost(Gx2, Gy2);
        }

        else if (nextlocation == 'P')
        {
            erasePac();
            score = 0;
            Px = 60;
            Py = 10;
            Px = Px + 1;
            printPac();
            lives--;
        }
    }
}

void printScore()
{
    gotoxy(90, 4);
    cout << "Your Score : " << score << "     ";
}

void printLives()
{
    gotoxy(90, 6);
    cout << "Lives : " << lives << "     ";
}

void moveChasingGhost()
{
    if (Gx3 > Px)
    {
        char next = GetCharAtxy(Gx3 - 1, Gy3);
        if (next == ' ')
        {
            clearGhost(Gx3, Gy3);
            Gx3 = Gx3 - 0.5;
            printGhost(Gx3, Gy3);
        }
        if (next == '.')
        {
            clearGhost(Gx3, Gy3);
            Gx3 = Gx3 - 0.5;
            printGhost(Gx3, Gy3);
            gotoxy(Gx3 + 0.5, Gy3);
            cout << ".";
        }
    }
    if (Gx3 < Px)
    {
        char next = GetCharAtxy(Gx3 + 1, Gy3);
        if (next == ' ')
        {
            clearGhost(Gx3, Gy3);
            Gx3 = Gx3 + 0.5;
            printGhost(Gx3, Gy3);
        }
        if (next == '.')
        {

            clearGhost(Gx3, Gy3);
            Gx3 = Gx3 + 0.5;
            printGhost(Gx3, Gy3);
            gotoxy(Gx3 - 0.5, Gy3);
            cout << ".";
        }
    }
    if (Gy3 > Py)
    {
        char next = GetCharAtxy(Gx3, Gy3 - 1);
        if (next == ' ')
        {
            clearGhost(Gx3, Gy3);
            Gy3 = Gy3 - 0.5;
            printGhost(Gx3, Gy3);
        }
        if (next == '.')
        {
            clearGhost(Gx3, Gy3);
            Gy3 = Gy3 - 0.5;
            printGhost(Gx3, Gy3);
            gotoxy(Gx3, Gy3 + 0.5);
            cout << ".";
        }
    }
    if (Gy3 < Py)
    {
        char next = GetCharAtxy(Gx3, Gy3 + 1);
        if (next == ' ')
        {
            clearGhost(Gx3, Gy3);
            Gy3 = Gy3 + 0.5;
            printGhost(Gx3, Gy3);
        }
        if (next == '.')
        {
            clearGhost(Gx3, Gy3);
            Gy3 = Gy3 + 0.5;
            printGhost(Gx3, Gy3);
            gotoxy(Gx3, Gy3 - 0.5);
            cout << ".";
        }
    }
}