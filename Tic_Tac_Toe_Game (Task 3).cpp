#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

char n1;
char n2;
int i = 0;
int count = 0;
char option;
string p1 = "";
string p2 = "";
char symbol1;
char symbol2;
int count2 = 0;

char format[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void rules(int row, int column, char symbol1);
void rules2(int row, int column, char symbol2);
void play(string p1, string p2);
void maping();
void maping2();
void play2(int option, string p1, string p2, int x);
void win();
void layout0();
void again();

void layout()
{
    cout << "--> Enter the name of player 1:- ";
    getline(cin, p1);

    cout << "--> Enter the name of player 2:- ";
    getline(cin, p2);

    cout << endl;
    layout0();

    play(p1, p2);
    cout << endl;
}

void layout0()
{
    cout << format[0][0] << " | " << format[0][1] << "  |" << format[0][2] << endl;
    cout << "__|____|__\n";
    cout << "  |    |\n";
    cout << format[1][0] << " | " << format[1][1] << "  |" << format[1][2] << endl;
    cout << "__|____|__\n";
    cout << "  |    |\n";
    cout << format[2][0] << " | " << format[2][1] << "  |" << format[2][2] << endl;
    cout << endl;
}

void play(string p1, string p2)
{
    cout << "--> Who wants first turn " << p1 << " or " << p2 << "?" << endl;
lol:
    cout << "> Press 1 for " << p1 << " or Press 2 for " << p2 << " :- ";
    cin >> option;
    cout << endl;

    if (!isdigit(option))
    {
        cout << " *Please enter correct value" << endl;
        goto lol;
    }
    if (option != '1' && option != '2')
    {
        cout << " *Please enter correct value" << endl;
        goto lol;
    }
    else
    {
        if (option == '1')
        {
        lol1:
            cout << p1 << " has first turn, press O for O or X for X :- ";
            cin >> symbol1;
            cout << endl;
            if (symbol1 != 'X' && symbol1 != 'O')
            {
                cout << endl;
                cout << "@ " << p1 << " please enter correct value" << endl;
                goto lol1;
            }
            if (symbol1 == 'X')
            {
                cout << p1 << " will play with - X" << endl;
                cout << p2 << " will play with - O" << endl;
                symbol2 = 'O';
                cout << endl;
            }
            else
            {
                cout << p1 << " will play with - O" << endl;
                cout << p2 << " will play with - X" << endl;
                symbol2 = 'X';
                cout << endl;
            }
        }
        else
        {
        lol2:
            cout << p2 << " has first turn, press O for O or X for X :- ";
            cin >> symbol2;
            cout << endl;
            if (symbol2 != 'X' && symbol2 != 'O')
            {
                cout << endl;
                cout << "@ " << p2 << " please enter correct value" << endl;
                goto lol2;
            }
            if (symbol2 == 'X')
            {
                cout << p2 << " will play with - X " << endl;
                cout << p1 << " will play with - O " << endl;
                symbol1 = 'O';
                cout << endl;
            }
            else
            {
                cout << p2 << " will play with - O " << endl;
                cout << p1 << " will play with - X " << endl;
                symbol1 = 'X';
                cout << endl;
            }
        }
        play2(option, p1, p2, i);
    }
}

void play2(int option, string p1, string p2, int x)
{
    if (i == 1)
        layout0();

    cout << "Press the number for place (between 1-9) where you want to enter O/X" << endl;
    cout << endl;
    if (option == '1')
    {
    again1:
        if (count2 < 10)
        {
            cout << p1 << " enter the number:- ";
            cin >> n1;
            count2++;
        }
        if (n1 == n2)
        {
            cout << p1 << " You can't enter at this place" << endl;
            count2--;
            goto again1;
        }
        if (!isdigit(n1))
        {
            cout << p1 << "--> Enter the correct value" << endl;
            count2--;
            goto again1;
        }
        if (n1 != '1' && n1 != '2' && n1 != '3' && n1 != '4' && n1 != '5' && n1 != '6' && n1 != '7' && n1 != '8' && n1 != '9')
        {
            cout << p1 << "--> Enter the correct value" << endl;
            count2--;
            goto again1;
        }
        maping();
    again2:
        if (count2 < 9)
        {
            cout << p2 << " enter the number:- ";
            cin >> n2;
            count2++;
            cout << endl;
        }
        if (n2 == n1)
        {
            cout << p2 << "--> Enter the correct value" << endl;
            count2--;
            goto again2;
        }
        if (!isdigit(n2))
        {
            cout << p2 << "--> Enter the correct value" << endl;
            count2--;
            goto again2;
        }
        if (n2 != '1' && n2 != '2' && n2 != '3' && n2 != '4' && n2 != '5' && n2 != '6' && n2 != '7' && n2 != '8' && n2 != '9')
        {
            cout << p2 << "--> Enter the correct value" << endl;
            count2--;
            goto again2;
        }

        maping2();
    }
    else
    {

    again3:
        if (count2 < 10)
        {
            cout << p2 << " Enter the number:- ";
            cin >> n2;
            count2++;
        }
        if (n1 == n2)
        {
            cout << p2 << "--> You can't enter at this place" << endl;
            count2--;
            goto again3;
        }
        if (!isdigit(n2))
        {
            cout << p2 << " Enter the correct value" << endl;
            count2--;
            goto again3;
        }
        if (n2 != '1' && n2 != '2' && n2 != '3' && n2 != '4' && n2 != '5' && n2 != '6' && n2 != '7' && n2 != '8' && n2 != '9')
        {
            cout << p2 << "--> Enter the correct value" << endl;
            count2--;
            goto again3;
        }

        maping2();
    again4:
        if (count2 < 9)
        {
            cout << p1 << " Enter the number:- ";
            cin >> n1;
            count2++;
            cout << endl;
        }
        if (n2 == n1)
        {
            cout << p1 << " You can't enter at this place" << endl;
            count2--;
            goto again4;
        }
        if (!isdigit(n1))
        {
            cout << p1 << "--> Enter the correct value" << endl;
            count2--;
            goto again4;
        }
        if (n1 != '1' && n1 != '2' && n1 != '3' && n1 != '4' && n1 != '5' && n1 != '6' && n1 != '7' && n1 != '8' && n1 != '9')
        {
            cout << p1 << "--> Enter the correct value" << endl;
            count--;
            goto again4;
        }

        maping();
    }
}

void maping()
{
    count++;
    if (count <= 9)
    {
        if (n1 == '1')
        {
            format[0][0] = symbol1;
        }
        else if (n1 == '2')
        {
            format[0][1] = symbol1;
        }
        else if (n1 == '3')
        {
            format[0][2] = symbol1;
        }
        else if (n1 == '4')
        {
            format[1][0] = symbol1;
        }
        else if (n1 == '5')
        {
            format[1][1] = symbol1;
        }
        else if (n1 == '6')
        {
            format[1][2] = symbol1;
        }
        else if (n1 == '7')
        {
            format[2][0] = symbol1;
        }
        else if (n1 == '8')
        {
            format[2][1] = symbol1;
        }
        else if (n1 == '9')
        {
            format[2][2] = symbol1;
        }
        if (count2 >= 4)
        {
            win();
        }
        if (option != '1')
        {
            i = 1;
            play2(option, p1, p2, i);
        }
    }
    layout0();
    cout << endl;
    if (count == 9)
    {
        layout0();
        win();
    }
}

void maping2()
{
    count++;
    if (count <= 9)
    {
        if (n2 == '1')
        {
            format[0][0] = symbol2;
        }
        else if (n2 == '2')
        {
            format[0][1] = symbol2;
        }
        else if (n2 == '3')
        {
            format[0][2] = symbol2;
        }
        else if (n2 == '4')
        {
            format[1][0] = symbol2;
        }
        else if (n2 == '5')
        {
            format[1][1] = symbol2;
        }
        else if (n2 == '6')
        {
            format[1][2] = symbol2;
        }
        else if (n2 == '7')
        {
            format[2][0] = symbol2;
        }
        else if (n2 == '8')
        {
            format[2][1] = symbol2;
        }
        else if (n2 == '9')
        {
            format[2][2] = symbol2;
        }
        if (count2 >= 4)
        {
            win();
        }
        if (option != '2')
        {
            i = 1;
            play2(option, p1, p2, i);
        }
    }
    layout0();
    cout << endl;
    if (count == 9)
    {
        layout0();
        win();
    }
}

void win()
{
    if (
        ((format[0][0] == 'X' && format[0][0] == format[1][1]) && (format[1][1] == format[2][2])) ||
        ((format[0][2] == 'X' && format[0][2] == format[1][1]) && (format[1][1] == format[2][0])) ||

        ((format[0][0] == 'X' && format[0][0] == format[0][1]) && (format[0][1] == format[0][2])) ||
        ((format[1][0] == 'X' && format[1][0] == format[1][1]) && (format[1][1] == format[1][2])) ||
        ((format[2][0] == 'X' && format[2][0] == format[2][1]) && (format[2][1] == format[2][2])) ||

        ((format[0][0] == 'X' && format[0][0] == format[1][0]) && (format[1][0] == format[2][0])) ||
        ((format[0][1] == 'X' && format[0][1] == format[1][1]) && (format[1][1] == format[2][1])) ||
        ((format[0][2] == 'X' && format[0][2] == format[1][2]) && (format[1][2] == format[2][2])))
    {

        if (option == '1')
        {
            if (symbol1 == 'X' && symbol2 == 'O')
            {
                layout0();
                cout << "\t\t" << p1 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
            else
            {
                layout0();
                cout << "\t\t" << p2 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
        }

        if (option == '2')
        {
            if (symbol1 == 'O' && symbol2 == 'X')
            {
                layout0();
                cout << "\t\t" << p2 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
            else
            {
                layout0();
                cout << "\t\t" << p1 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
        }
    }
    else if (
        ((format[0][0] == 'O' && format[0][0] == format[1][1]) && (format[1][1] == format[2][2])) ||
        ((format[0][2] == 'O' && format[0][2] == format[1][1]) && (format[1][1] == format[2][0])) ||

        ((format[0][0] == 'O' && format[0][0] == format[0][1]) && (format[0][1] == format[0][2])) ||
        ((format[1][0] == 'O' && format[1][0] == format[1][1]) && (format[1][1] == format[1][2])) ||
        ((format[2][0] == 'O' && format[2][0] == format[2][1]) && (format[2][1] == format[2][2])) ||

        ((format[0][0] == 'O' && format[0][0] == format[1][0]) && (format[1][0] == format[2][0])) ||
        ((format[0][1] == 'O' && format[0][1] == format[1][1]) && (format[1][1] == format[2][1])) ||
        ((format[0][2] == 'O' && format[0][2] == format[1][2]) && (format[1][2] == format[2][2])))
    {

        if (option == '1')
        {
            if (symbol1 == 'O' && symbol2 == 'X')
            {
                layout0();
                cout << "\t\t" << p1 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
            else
            {
                layout0();
                cout << "\t\t" << p2 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
        }

        if (option == '2')
        {
            if (symbol1 == 'X' && symbol2 == 'O')
            {
                layout0();
                cout << "\t\t" << p2 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
            else
            {
                layout0();
                cout << "\t\t" << p1 << " Wins.";
                cout << endl;
                cout << endl;
                cout << endl;
                again();
            }
        }
    }

    else if ((count == 9) && ((format[0][0] != format[1][1]) ||
                              (format[0][2] != format[1][1]) ||

                              (format[0][0] != format[0][1]) ||
                              (format[1][0] != format[1][1]) ||
                              (format[2][0] != format[2][1]) ||

                              (format[0][0] != format[1][0]) ||
                              (format[0][1] != format[1][1]) ||
                              (format[0][2] != format[1][2])))
    {
        cout << "\t\t\t----------------" << endl;
        cout << "\t\t\t| Game is DRAW |" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        again();
    }
}

void again()
{
    char chh;
    cout << "Do you want to play again" << endl;
    cout << "Press y/n:- ";
    cin >> chh;
    if (chh == 'y')
    {
        cin.ignore();
        layout();
    }
    else if (chh == 'n')
    {
        exit(0);
        cout << endl;
        cout << endl;
    }
    else
    {
        cout << "--> Please enter correct value" << endl;
    }
}

int main()
{
    system("CLS");
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\t| WELCOME TO TIC TOE GAME |" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << endl
         << endl;
    layout();
}
