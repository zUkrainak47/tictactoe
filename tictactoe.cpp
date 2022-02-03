#include <iostream>
using namespace std;

string num = "     1   2   3";
string line = "    -----------";
string middle = "   | - + - + - |";

void prnt(char f[3], char s[3], char t[3]) 
{
    cout << 
    num << '\n' << 
    line << '\n' << 
    " a | " << f[0] << " | " << f[1] << " | " << f[2] << " |" << '\n' << 
    middle << '\n' << 
    " b | " << s[0] << " | " << s[1] << " | " << s[2] << " |" << '\n' << 
    middle << '\n' <<
    " c | " << t[0] << " | " << t[1] << " | " << t[2] << " |" << '\n' << 
    line << '\n' << '\n';
}

int flag = 0;

void change(char f[3], char s[3], char t[3], char let, char number, char turn) {
    if (let == 'a') {
        if (f[number - 1] == ' ') {
            f[number - 1] = turn;
            flag = 1;
        }
    }
    else if (let == 'b') {
        if (s[number - 1] == ' ') {
            s[number - 1] = turn;
            flag = 1;
        }
    }
    else if (let == 'c') {
        if (t[number - 1] == ' ') {
            t[number - 1] = turn;
            flag = 1;
        }
    }
}

int main()
{
    char first[] =  "   ";
    char second[] = "   ";
    char third[] = "   ";

    cout << "\ninput format: \"a 1\" if you wish to place your sign in the upper left corner\n\n";

    char win = ' ';
    char letter; 
    int number;
    string inp;
    char turn = 'x';
    int turns = 0;
    while (win == ' ') {
        prnt(first, second, third);
        while (true) {
            cout << "player " << turn << "'s turn. input coordinates of desired turn: ";
            cin >> letter >> number;
            if ((letter == 'a' || letter == 'b' ||letter == 'c') && (number == 1 || number == 2 || number == 3)) {
                change (first, second, third, letter, number, turn);
                if (flag == 1) {
                    flag = 0;
                    break;
                }
                else cout << "\ndont try to break the program #2\n";
            }
            else cout << "\ndont try to break the program\n";
        }
        cout << '\n';
        if ((first[0] == first[1] && first[1] == first[2] && first[0] != ' ') || 
            (second[0] == second[1] && second[1] == second[2] && second[1] != ' ') || 
            (third[0] == third[1] && third[1] == third[2] && third[1] != ' ') || 
            (first[0] == second[0] && second[0] == third[0] && first[0] != ' ') || 
            (first[1] == second[1] && second[1] == third[1] && second[1] != ' ') || 
            (first[2] == second[2] && second[2] == third[2] && second[2] != ' ') || 
            (first[0] == second[1] && second[1] == third[2] && first[0] != ' ') || 
            (first[2] == second[1] && second[1] == third[0] && second[1] != ' ')) 
        {
            win = turn;
            prnt(first, second, third);
            cout << "player " << turn << " won\n";
        }
        else if (turn == 'x')
            turn = 'o';
        else turn = 'x';
        turns++;
        if (turns == 9) {
            prnt(first, second, third);
            cout << "tie\n";
            break;
        }
    }

    //      1   2   3
    //     -----------
    //  a | x | o |   |
    //    | - + - + - |
    //  b |   | x |   |
    //    | - + - + - |
    //  c |   |   | o |
    //     -----------

    return 0;
}

